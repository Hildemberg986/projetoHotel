#ifndef screens_H
#define screens_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char main_menu_screen(void);
void about_screen(void);
void team_screen(void);
char login_screen(void);
void registration_login_screen(void);
bool login_client(void);
void login_admin(void);
void client_sale(void);

struct registration_login
{
    char name[99];
    char cpf[12];
    char email[100];
    char password[100];
};

#endif