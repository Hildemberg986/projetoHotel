#ifndef reservation_screens_H
#define reservation_screens_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../function/database_functions.h"
#include "../function/utility_functions.h"
void register_reservation_screen(void);
void edit_reservation_screen(void);
void delete_reservation_screen(void);
void read_reservation_screen(void);
char reservation_menu(void);
#endif