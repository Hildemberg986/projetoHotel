#ifndef client_screens_H
#define client_screens_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void register_client_screen(void);
struct register_client
{
    char name[99];
    char cpf[12];
    char fone[20];
};
#endif