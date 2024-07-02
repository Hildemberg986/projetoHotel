#ifndef client_screens_H
#define client_screens_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../function/utility_functions.h"
#include "../function/database_functions.h"
void register_client_screen(void);
void edit_client_screen(void);
void delete_client_screen(void);
void read_client_screen(void);
char client_menu(void);

#endif