#ifndef database_functions_H
#define database_functions_H
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "../screens/reservation_screens.h"
typedef struct register_client
{
    char name[99];
    char cpf[12];
    char fone[20];
} Client;
typedef struct register_reservation
{
    char number[99];
    char day_enter[99];
    char day_exit[99];
    char client_cpf[12];
}Reservation;
void add_client(Client new_client);
void save_file_client(Client new_client);
void load_file_client();
void search_reservation(const char *cpf);
void save_file_reservation(Reservation new_reservation);
const char *search_client_cpf(const char *cpf, bool silentSearch);
#endif