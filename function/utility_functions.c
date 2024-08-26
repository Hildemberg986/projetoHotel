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
    do
    {
        printf("###   --> Digite o CPF do Cliente... ");
        scanf("%12[^\n]", cpf);
        getchar();

        // Chama a função para validar o CPF
        cpf_valido = valida_cpf(cpf);

        if (!cpf_valido)
        {
            if (!first)
                clear_last_lines(2);
            else
                clear_last_lines(1);
            printf("\t\t\tCPF inválido. Por favor, digite novamente.\n");
        };
        first = false;
    } while (!cpf_valido);
    return *cpf;
}

char* return_end_reservation()
{
    char *reservation_number = malloc(12);
    if (reservation_number == NULL) {
        // Falha ao alocar memória
        return NULL;
    }
    
    // Inicializa reservation_number com "0001"
    strcpy(reservation_number, "0000");

    FILE *arquivo = fopen("reservas.db", "rb");
    if (arquivo != NULL)
    {
        Reservation *loaded_reservation = malloc(sizeof(Reservation));
        if (loaded_reservation == NULL) {
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
        int number = atoi(reservation_number); // Converte a string para inteiro
        number++; // Incrementa o número
        snprintf(reservation_number, 12, "%04d", number); // Formata como 4 dígitos
    }

    return reservation_number;
}