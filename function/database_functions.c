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

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Client client;

    while (fread(&client, sizeof(Client), 1, arquivo) == 1) {
        if (strcmp(client.cpf, old_client.cpf) == 0) {
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
    // Abre o arquivo para leitura binária
    FILE *arquivo = fopen("reservas.db", "rb");

    if (arquivo != NULL)
    {
        Reservation *loaded_reservation = malloc(sizeof(Reservation));

        if (loaded_reservation == NULL)
        {
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
            return NULL;
        }

        // Lê enquanto conseguir ler reservas no arquivo
        while (fread(loaded_reservation, sizeof(Reservation), 1, arquivo) == 1)
        {
            printf("%s \n",loaded_reservation->client_cpf);
            // Compara o valor do cpf passado como parametro com os CPFs recuperados do arquivo
            if (strcmp(cpf, loaded_reservation->client_cpf) == 0)
            {
                fclose(arquivo);
                return loaded_reservation;
            }
        }

        // Fecha o arquivo aberto
        fclose(arquivo);

        // Libera a memória alocada caso não encontre a reserva
        free(loaded_reservation);
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
            if (strcmp(id, loaded_reservation->reservation_number) == 0)
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

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Reservation reservation;

    while (fread(&reservation , sizeof(Reservation), 1, arquivo) == 1) {
        if (strcmp(reservation.reservation_number, old_reservation.reservation_number) == 0) {
            // Mover o ponteiro de volta para o início do registro encontrado
            fseek(arquivo, -sizeof(Reservation), SEEK_CUR);
            // Escrever o novo cliente no lugar do antigo
            fwrite(&new_reservation, sizeof(Reservation), 1, arquivo);
            break;
        }
    }

    fclose(arquivo);
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
            if (strcmp(number, loaded_room_copy->number) == 0)
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