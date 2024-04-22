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

    // Mensagem de sucesso
    // printf("Cliente adicionado com sucesso!\n");
}