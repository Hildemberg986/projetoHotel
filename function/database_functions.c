#include "database_functions.h"
#define MAX_CLIENTS 2
Client clients[MAX_CLIENTS];
int cont_client = 0;

void add_client(Client new_client)
{
    // Verifica se o limite máximo de clientes foi atingido
    if (cont_client >= MAX_CLIENTS)
    {
        printf("Lista de clientes está cheia. Não é possível adicionar mais clientes.\n");
        getchar();
        return;
    }
    // Adiciona o novo cliente ao array de clientes
    clients[cont_client] = new_client;

    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        // Use uma string de formato para imprimir os dados de `clients[i]`
        printf("Nome: %s, CPF: %s, Fone: %s\n", clients[i].name, clients[i].cpf, clients[i].fone);
    }
    getchar();

    // salvarClientes("clientes.bd");
    cont_client++;
    printf("Cliente adicionado com sucesso!\n");
}
void save_file_client(const char *nomeArquivo, Client new_client)
{
    FILE *arquivo = fopen(nomeArquivo, "ab"); // Abre o arquivo para escrita binária

    if (arquivo != NULL) {
        fwrite(&new_client, sizeof(Client), 1, arquivo); // Escreve um único objeto Client no arquivo
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}
void load_file_client(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb"); // Abre o arquivo para leitura binária

    if (arquivo != NULL) {
        Client loaded_client;

        // Lê enquanto houver clientes no arquivo
        while (fread(&loaded_client, sizeof(Client), 1, arquivo) == 1) {
            // Exibe os dados lidos
            printf("Cliente carregado:\n");
            printf("Nome: %s\n", loaded_client.name);
            printf("Telefone: %s\n", loaded_client.fone);
            printf("CPF: %s\n", loaded_client.cpf);
            printf("\n"); // Adiciona uma linha em branco entre clientes
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}
