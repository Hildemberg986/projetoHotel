#include "database_functions.h"
void add_client(Client clients[], Client new_client)
{
    // Verifica se o limite máximo de clientes foi atingido
    // if (*client_count >= MAX_CLIENTS) {
    //     printf("Lista de clientes está cheia. Não é possível adicionar mais clientes.\n");
    //     return;
    // }
    // Adiciona o novo cliente ao array de clientes
        clients[0] = new_client;

    for (int i = 0; i < 10; i++)
    {
        // Use uma string de formato para imprimir os dados de `clients[i]`
        printf("Nome: %s, CPF: %s, Fone: %s\n", clients[i].name, clients[i].cpf, clients[i].fone);
    }
    getchar();

    salvarClientes("clientes.bd",clients);
    printf("Cliente adicionado com sucesso!\n");
}
void salvarClientes(const char *nomeArquivo, Client clients[]) {
    // int tamanho = sizeof(clients) / sizeof(Client);
    int tamanho = 10;
    // FILE *arquivo = fopen(nomeArquivo, "w"); // Abrir o arquivo para escrita

    // if (arquivo != NULL) {
    //     // Escrever a lista no arquivo
    //     fwrite(clients, sizeof(Client), tamanho, arquivo);

    //     // Fechar o arquivo
    //     fclose(arquivo);
    // } else {
    //     printf("Erro ao abrir o arquivo para escrita.\n");
    // }
    FILE *arquivo = fopen(nomeArquivo, "w"); // Abrir o arquivo para escrita em modo texto

    if (arquivo != NULL) {
        // Escrever a lista no arquivo
        for (int i = 0; i < tamanho; i++) {
            fprintf(arquivo, "%s;%s;%s\n", clients[i].name, clients[i].cpf, clients[i].fone);
        }

        // Fechar o arquivo
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}
