#include "database_functions.h"

//----------------------------------------cliente--------------------------------------------------
void save_file_client(Client new_client)
{
    // Abre o arquivo e define um ponteiro para o mesmo
    FILE *arquivo = fopen("clientes.db", "ab");

    if (arquivo != NULL)
    {
        // Escreve o valor new_client do tamanho do tipo Client uma vez no arquivo
        fwrite(&new_client, sizeof(Client), 1, arquivo);
        // Fecha o arquivo aberto
        fclose(arquivo);
    }
    else
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}
void load_file_client()
{
    // Abre o arquivo e define um ponteiro para o mesmo
    FILE *arquivo = fopen("clientes.db", "rb");
    if (arquivo != NULL)
    {
        // Cria uma variavel temporaria do tipo Client, um struct relacional
        Client loaded_client;

        // Lê enquanto houver clientes no arquivo
        while (fread(&loaded_client, sizeof(Client), 1, arquivo) == 1)
        {
            // Exibe os dados do cliente carregado
            printf("Cliente carregado:\n");
            printf("Nome: %s\n", loaded_client.name);
            printf("Telefone: %s\n", loaded_client.fone);
            printf("CPF: %s\n", loaded_client.cpf);
        }
        // Fecha o arquivo aberto
        fclose(arquivo);
    }
    else
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}

Client *search_client_cpf(const char *cpf)
{
    FILE *arquivo = fopen("clientes.db", "rb"); // Abre o arquivo para leitura binária

    if (arquivo != NULL)
    {
        Client *loaded_client = malloc(sizeof(Client));

        if (loaded_client == NULL)
        {
            // Lida com a falha de alocação de memória
            return NULL;
        }

        // Lê enquanto conseguir ler o valor do tipo Client
        while (fread(loaded_client, sizeof(Client), 1, arquivo) == 1)
        {
            // Compara o parametro CPF com os valores dos CPFs recuperados do arquivo
            if (strcmp(cpf, loaded_client->cpf) == 0 && loaded_client->del != true)
            {
                return loaded_client;
            }
        }
        // Fecha o arquivo aberto
        free(loaded_client);
        fclose(arquivo);
        return NULL;
    }
    else
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }
}

void edit_client(Client old_client, Client new_client)
{
    FILE *arquivo = fopen("clientes.db", "rb+");

    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Client client;

    while (fread(&client, sizeof(Client), 1, arquivo) == 1)
    {
        if (strcmp(client.cpf, old_client.cpf) == 0 && client.del != true)
        {
            // Mover o ponteiro de volta para o início do registro encontrado
            fseek(arquivo, -sizeof(Client), SEEK_CUR);
            // Escrever o novo cliente no lugar do antigo
            fwrite(&new_client, sizeof(Client), 1, arquivo);
            break;
        }
    }

    fclose(arquivo);
}

//----------------------------------------------- Reservas ------------------------------------------------------

void save_file_reservation(Reservation new_reservation)
{
    // Abre o arquivo para escrita binária e define um ponteiro
    FILE *arquivo = fopen("reservas.db", "ab");

    if (arquivo != NULL)
    {
        // Escreve um único objeto Client no arquivo
        fwrite(&new_reservation, sizeof(Reservation), 1, arquivo);
        // Fecha o arquivo aberto
        fclose(arquivo);
    }
    else
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

Reservation *search_reservation_cpf(const char *cpf)
{
    Client *load_client_copy;
    Reservation loaded_reservation;
    // Abre o arquivo para leitura binária
    FILE *arquivo = fopen("reservas.db", "rb");

    if (arquivo != NULL)
    {
        // Reservation *loaded_reservation = malloc(sizeof(Reservation));

        // if (loaded_reservation == NULL)
        // {
        //     printf("Erro ao alocar memória.\n");
        //     fclose(arquivo);
        //     return NULL;
        // }
        load_client_copy = search_client_cpf(cpf);
        if (load_client_copy != NULL)
        {
            while (fread(&loaded_reservation, sizeof(Reservation), 1, arquivo) == 1)
            {
                // Compara o valor do cpf passado como parametro com os CPFs recuperados do arquivo
                if (strcmp(cpf, loaded_reservation.client_cpf) == 0 && loaded_reservation.del != true)
                {
                    // Imprime os dados buscados na tela
                    printf("###############################################################################\n");
                    printf("\n");
                    printf("Name: %s\n", load_client_copy->name);
                    printf("Número de telefone: %s\n", load_client_copy->fone);
                    printf("Número da Reserva: %s\n", loaded_reservation.reservation_number);
                    printf("Número do quarto: %s\n", loaded_reservation.room_number);
                    printf("Check in: %s\n", loaded_reservation.day_enter);
                    printf("Check out: %s\n", loaded_reservation.day_exit);
                    printf("\n");
                }
            }
            free(load_client_copy);
            return NULL;
        }

        // Fecha o arquivo aberto
        fclose(arquivo);
        printf("Não há Reservas Para Esse CPF.\n");
        return NULL;
    }
    else
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }
}

Reservation *search_reservation_id(const char *id)
{
    // Abre o arquivo para escrita binária e define um ponteiro para o mesmo
    FILE *arquivo = fopen("reservas.db", "rb");

    if (arquivo != NULL)
    {
        Reservation *loaded_reservation = malloc(sizeof(Reservation));

        // Lê enquanto conseguir ler reservas no arquivo e o valor for diferete de 1
        while (fread(loaded_reservation, sizeof(Reservation), 1, arquivo) == 1)
        {
            // Compara o valor do cpf passado como parametro com os CPFs recuperados do arquivo
            if (strcmp(id, loaded_reservation->reservation_number) == 0 && loaded_reservation->del != true)
            {
                return loaded_reservation;
            }
        }
        // Fecha o arquivo aberto
        fclose(arquivo);
        return NULL;
    }
    else
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }
}

void edit_reservation(Reservation old_reservation, Reservation new_reservation)
{
    FILE *arquivo = fopen("reservas.db", "rb+");

    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Reservation reservation;

    while (fread(&reservation, sizeof(Reservation), 1, arquivo) == 1)
    {
        if (strcmp(reservation.reservation_number, old_reservation.reservation_number) == 0 && reservation.del != true)
        {
            // Mover o ponteiro de volta para o início do registro encontrado
            fseek(arquivo, -sizeof(Reservation), SEEK_CUR);
            // Escrever o novo cliente no lugar do antigo
            fwrite(&new_reservation, sizeof(Reservation), 1, arquivo);
            break;
        }
    }

    fclose(arquivo);
}
bool check_date_room(char *room_number, char *date_enter, char *date_exit)
{
    FILE *arquivo = fopen("reservas.db", "rb");

    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return false;
    }

    Reservation reservation;

    while (fread(&reservation, sizeof(Reservation), 1, arquivo) == 1)
    {
        if (strcmp(reservation.room_number, room_number) == 0 && reservation.del != true)
        {
            if (!(compare_date(reservation.day_enter,reservation.day_exit,date_enter,date_exit)))
            {
                fclose(arquivo);
                return false;
            }
            
        }
    }
    fclose(arquivo);
    return true;
}

//-------------------------------------------------- Quartos ----------------------------------------------

void save_file_room(Room new_room)
{
    // Abre o arquivo para escrita binária e define um ponteiro
    FILE *arquivo = fopen("roons.db", "ab");

    if (arquivo != NULL)
    {
        // Escreve um único objeto Room no arquivo
        fwrite(&new_room, sizeof(Room), 1, arquivo);
        // Fecha o arquivo aberto
        fclose(arquivo);
    }
    else
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

Room *search_room(const char *number)
{
    // Abre o arquivo para escrita binária e define um ponteiro para o mesmo
    FILE *arquivo = fopen("roons.db", "rb");
    if (arquivo != NULL)
    {
        Room *loaded_room_copy;

        loaded_room_copy = (Room *)malloc(sizeof(Room));

        // Lê enquanto conseguir ler reservas no arquivo e o valor for diferete de 1
        while (fread(loaded_room_copy, sizeof(Room), 1, arquivo) == 1)
        {
            // Compara o valor do cpf passado como parametro com os CPFs recuperados do arquivo
            if (strcmp(number, loaded_room_copy->number) == 0 && loaded_room_copy->del != true)
            {
                return loaded_room_copy;
            }
        }
        // Fecha o arquivo aberto
        fclose(arquivo);
        return NULL;
    }
    else
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }
}

void edit_room(Room old_room, Room new_room)
{
    FILE *arquivo = fopen("roons.db", "rb+");

    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Room room;

    while (fread(&room, sizeof(Room), 1, arquivo) == 1)
    {
        if (strcmp(room.number, old_room.number) == 0 && room.del != true)
        {
            // Mover o ponteiro de volta para o início do registro encontrado
            fseek(arquivo, -sizeof(Room), SEEK_CUR);
            // Escrever o novo cliente no lugar do antigo
            fwrite(&new_room, sizeof(Room), 1, arquivo);
            break;
        }
    }

    fclose(arquivo);
}