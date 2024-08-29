#include "utility_functions.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void initial_files()
{

    FILE *arquivo1 = fopen("roons.db", "ab");
    fclose(arquivo1);
    FILE *arquivo2 = fopen("reservas.db", "ab");
    fclose(arquivo2);
    FILE *arquivo3 = fopen("clientes.db", "ab");
    fclose(arquivo3);
}

// Retirado do chatGPT
void clean_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void sleep_code(int seconds)
{
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif
}

bool valida_cpf(const char *imputCPF)
{
    char cpf_format[12]; // Declare um array para armazenar o CPF formatado
    char cpf[12];        // Declare um array para armazenar o CPF sem formatação
    int i = 0;
    int j = 0;

    // Percorre o CPF com pontos e traço, copiando apenas os dígitos
    while (imputCPF[i])
    {
        if (isdigit(imputCPF[i]))
        {
            cpf_format[j++] = imputCPF[i];
        }
        i++;
    }
    cpf_format[j] = '\0'; // Adicione o caractere nulo ao final do array formatado

    strcpy(cpf, cpf_format); // Copie o CPF formatado para o CPF não formatado

    // Verifica se o CPF tem 11 dígitos
    if (strlen(cpf) != 11)
    {
        return false;
    }

    // Verifica se todos os dígitos são iguais, o que é inválido para um CPF válido
    for (i = 1; i < 11; i++)
    {
        if (cpf[i] != cpf[0])
        {
            break;
        }
    }
    if (i == 11)
    {
        return false;
    }

    // Calcula o primeiro dígito verificador
    int soma = 0;
    int peso = 10;
    for (i = 0; i < 9; i++)
    {
        soma += (cpf[i] - '0') * peso;
        peso--;
    }
    int digito1 = soma % 11;
    if (digito1 < 2)
    {
        digito1 = 0;
    }
    else
    {
        digito1 = 11 - digito1;
    }
    if (digito1 != cpf[9] - '0')
    {
        return false;
    }

    // Calcula o segundo dígito verificador
    soma = 0;
    peso = 11;
    for (i = 0; i < 10; i++)
    {
        soma += (cpf[i] - '0') * peso;
        peso--;
    }
    int digito2 = soma % 11;
    if (digito2 < 2)
    {
        digito2 = 0;
    }
    else
    {
        digito2 = 11 - digito2;
    }
    if (digito2 != cpf[10] - '0')
    {
        return false;
    }

    // Se passou por todas as verificações, o CPF é válido
    return true;
}
void clear_last_lines(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\033[F\033[K"); // Move o cursor para cima e limpa a linha
    }
}
char read_cpf(char *cpf)
{
    bool first = true;
    int cpf_valido = false;
    Client *client;

    do
    {
        printf("###   --> Digite o CPF do Cliente... ");
        scanf("%11s", cpf); // Limite para evitar buffer overflow
        getchar();          // Consumir o '\n'

        // Chama a função para validar o CPF
        cpf_valido = valida_cpf(cpf);

        // Verifica se o CPF já existe no sistema
        client = search_client_cpf(cpf);

        // Se o CPF já existe, ele não é válido para um novo registro
        if (client != NULL && strcmp(client->cpf, cpf) == 0)
        {
            cpf_valido = false;
        }

        if (!cpf_valido)
        {
            if (!first)
                clear_last_lines(2);
            else
                clear_last_lines(1);

            printf("\t\t\tCPF inválido ou já cadastrado. Por favor, digite novamente.\n");
        }

        first = false;
    } while (!cpf_valido);

    return *cpf; // Retorna o ponteiro para o CPF
}

char *return_end_reservation()
{
    char *reservation_number = malloc(12);
    if (reservation_number == NULL)
    {
        // Falha ao alocar memória
        return NULL;
    }

    // Inicializa reservation_number com "0001"
    strcpy(reservation_number, "0000");

    FILE *arquivo = fopen("reservas.db", "rb");
    if (arquivo != NULL)
    {
        Reservation *loaded_reservation = malloc(sizeof(Reservation));
        if (loaded_reservation == NULL)
        {
            // Falha ao alocar memória
            fclose(arquivo);
            free(reservation_number);
            return NULL;
        }

        while (fread(loaded_reservation, sizeof(Reservation), 1, arquivo) == 1)
        {
            // Atualiza reservation_number se encontrar uma reserva
            strcpy(reservation_number, loaded_reservation->reservation_number);
        }

        free(loaded_reservation);
        fclose(arquivo);

        // Incrementa o número da reserva encontrado
        int number = atoi(reservation_number);            // Converte a string para inteiro
        number++;                                         // Incrementa o número
        snprintf(reservation_number, 12, "%04d", number); // Formata como 4 dígitos
    }

    return reservation_number;
}
char *read_cpf_Consult()
{
    static char cpf[12];
    bool first = true;
    int cpf_valido = false;
    Client *client;
    do
    {
        printf("###   --> Digite o CPF do Cliente... ");
        scanf("%12[^\n]", cpf);
        getchar();

        // Chama a função para validar o CPF
        cpf_valido = valida_cpf(cpf);

        client = search_client_cpf(cpf);

        if (client == NULL || strcmp(client->cpf, cpf) != 0)
        {
            cpf_valido = false;
        }
        if (strcmp(cpf, "000") == 0)
        {
            cpf_valido = true;
        }

        if (!cpf_valido)
        {
            if (!first)
                clear_last_lines(2);
            else
                clear_last_lines(1);
            printf("\t\t\tCPF inválido ou Não cadastrado. Por favor, digite novamente.\n");
            printf("\t\t\tDigite 000 Se Quiser Cancelar a Operação\n");
        };
        first = false;
    } while (!cpf_valido);
    return cpf;
}

char *read_room_Consult()
{
    static char room_number[99];
    bool first = true;
    int valido = false;
    Room *room;
    do
    {
        printf("###   --> Digite o Numero do Quarto a Ser Reservado... ");
        scanf("%99[^\n]", room_number);
        getchar();

        room = search_room(room_number);

        if (room != NULL && strcmp(room->number, room_number) == 0)
        {
            valido = true;
        }
        if (strcmp(room_number, "000") == 0)
        {
            valido = true;
        }

        if (!valido)
        {
            if (!first)
                clear_last_lines(2);
            else
                clear_last_lines(1);
            printf("\t\t\tNúmero de Quarto Não cadastrado. Por favor, digite novamente.\n");
            printf("\t\t\tDigite 000 Se Quiser Cancelar a Operação\n");
        };
        first = false;
    } while (!valido);
    return room_number;
}
char read_room(char *room_number)
{
    bool first = true;
    int valido = false;
    Room *room;

    do
    {
        printf("###   --> Digite o Numero do Quarto... ");
        scanf("%99s", room_number); // Limite para evitar buffer overflow
        getchar();                  // Consumir o '\n'

        // Verifica se o CPF já existe no sistema
        room = search_room(room_number);

        // Se o CPF já existe, ele não é válido para um novo registro
        if (room != NULL && strcmp(room->number, room_number) == 0)
        {
            valido = false;
        }
        else
        {
            valido = true;
        }

        if (!valido)
        {
            if (!first)
                clear_last_lines(2);
            else
                clear_last_lines(1);

            printf("\t\t\tQuarto já cadastrado. Por favor, digite novamente.\n");
        }

        first = false;
    } while (!valido);

    return *room_number; // Retorna o ponteiro para o CPF
}

bool valida_data(const char *date)
{
    int day, month, year;
    bool bissexto;

    // Lê a data no formato DD/MM/AAAA
    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3)
    {
        return false; // Formato inválido
    }

    // Verifica se o ano é válido
    if (year < 2024 || year > 9999)
    {
        return false;
    }

    // Verifica se o ano é bissexto
    bissexto = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    // Verifica se o mês é válido
    if (month < 1 || month > 12)
    {
        return false;
    }

    // Número de dias em cada mês
    int days_in_month[] = {31, 28 + bissexto, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Verifica se o dia é válido para o mês e ano dados
    if (day < 1 || day > days_in_month[month - 1])
    {
        return false;
    }

    return true;
}
char read_date(char *date, char *texto)
{
    bool first = true;
    int valido = false;

    do
    {
        printf("%s", texto);
        scanf("%99s", date); // Limite para evitar buffer overflow
        getchar();           // Consumir o '\n'

        valido = valida_data(date);

        if (!valido)
        {
            if (!first)
                clear_last_lines(2);
            else
                clear_last_lines(1);

            printf("\t\t\tData Inválida. Por favor, digite novamente.\n");
        }

        first = false;
    } while (!valido);

    return *date; // Retorna o ponteiro para o CPF
}