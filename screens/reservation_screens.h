#ifndef reservation_screens_H
#define reservation_screens_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct register_reservation
{
    char number[99];
    char day_enter[99];
    char day_exit[99];
    char client_cpf[12];
}Reservation;

void register_reservation_screen(void);
void edit_reservation_screen(void);
void delete_reservation_screen(void);
void read_reservation_screen(void);
char reservation_menu(void);
#endif