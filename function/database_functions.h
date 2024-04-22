#ifndef database_functions_H
#define database_functions_H
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
typedef struct register_client
{
    char name[99];
    char cpf[12];
    char fone[20];
} Client;

void add_client(Client clients[], Client new_client);
void salvarClientes(const char *nomeArquivo, Client clients[]);
#endif