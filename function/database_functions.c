#include "database_functions.h"

void save_file_client(Client new_client)
{
    //Abre o arquivo e define um ponteiro para o mesmo
    FILE *arquivo = fopen("clientes.db", "ab");

    if (arquivo != NULL)
    {
        //Escreve o valor new_client do tamanho do tipo Client uma vez no arquivo
        fwrite(&new_client, sizeof(Client), 1, arquivo);
        //Fecha o arquivo aberto
        fclose(arquivo);
    }
    else
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}
void load_file_client()
{
    //Abre o arquivo e define um ponteiro para o mesmo
    FILE *arquivo = fopen("clientes.db", "rb"); 
    if (arquivo != NULL)
    {
        //Cria uma variavel temporaria do tipo Client, um struct relacional 
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
        //Fecha o arquivo aberto
        fclose(arquivo);
    }
    else
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}

const char *search_client_cpf(const char *cpf, bool silentSearch)
{
    FILE *arquivo = fopen("clientes.db", "rb"); // Abre o arquivo para leitura binária

    if (arquivo != NULL)
    {
        Client loaded_client;

        // Lê enquanto conseguir ler o valor do tipo Client
        while (fread(&loaded_client, sizeof(Client), 1, arquivo) == 1)
        {
            //Compara o parametro CPF com os valores dos CPFs recuperados do arquivo
            if (strcmp(cpf, loaded_client.cpf) == 0)
            {
                if (silentSearch)
                {
                    fclose(arquivo);
                    // cria um valor estatico para armazenar o nome do cliente
                    static char nome_copy[99];
                    strncpy(nome_copy, loaded_client.name, sizeof(nome_copy) - 1);
                    nome_copy[sizeof(nome_copy) - 1] = '\0';
                    return nome_copy;
                }
                else
                {   
                    //Exibe os valores do cliente pesquisado
                    printf("Cliente carregado:\n");
                    printf("Nome: %s\n", loaded_client.name);
                    printf("Telefone: %s\n", loaded_client.fone);
                    printf("CPF: %s\n", loaded_client.cpf);
                    fclose(arquivo);
                    return NULL;
                }
                break;
            }
        }
        //Fecha o arquivo aberto
        fclose(arquivo);
        return NULL;
    }
    else
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }
}

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

void search_reservation(const char *cpf)
{
    // Abre o arquivo para escrita binária e define um ponteiro para o mesmo
    FILE *arquivo = fopen("reservas.db", "rb");

    if (arquivo != NULL)
    {
        Reservation loaded_reservation;

        // Lê enquanto conseguir ler reservas no arquivo e o valor for diferete de 1
        while (fread(&loaded_reservation, sizeof(Reservation), 1, arquivo) == 1)
        {
            // Compara o valor do cpf passado como parametro com os CPFs recuperados do arquivo
            if (strcmp(cpf, loaded_reservation.client_cpf) == 0)
            {
                // Busca o nome do cliente ao qual o CPF esta vinculado e armazena em um ponteiro constante
                const char *name = search_client_cpf(cpf, true);

                // Exibe os dados da reserva e o nome da pessoa que reservou 
                printf("Reserva %s:\n", loaded_reservation.number);
                printf("Nome: %s\n", name);
                printf("Dia de Entrada: %s\n", loaded_reservation.day_enter);
                printf("Dia de Sáida: %s\n", loaded_reservation.day_exit);
            }
        }
        // Fecha o arquivo aberto
        fclose(arquivo);
    }
    else
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}
