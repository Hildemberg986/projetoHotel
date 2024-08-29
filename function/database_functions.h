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
    bool del;
} Client;

typedef struct register_reservation
{
    char reservation_number[12];
    char room_number[99];
    char day_enter[99];
    char day_exit[99];
    char client_cpf[12];
    bool del;
}Reservation;

typedef struct register_room
{
    char number[99];
    char type[99];
    char value[99];
    char quantity[99];
    bool del;
}Room;

void save_file_client(Client new_client);
void load_file_client();
void edit_client(Client old_client, Client new_client);
Reservation *search_reservation_cpf(const char *cpf);
Reservation *search_reservation_id(const char *id);
Room *search_room(const char *number);
Client *search_client_cpf(const char *cpf);
void save_file_reservation(Reservation new_reservation);
void edit_reservation(Reservation old_reservation, Reservation new_reservation);
void save_file_room(Room new_room);
void edit_room(Room old_room, Room new_room);
bool check_date_room(char *room_number, char *date_enter, char *date_exit);

#endif