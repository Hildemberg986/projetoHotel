#ifndef screens_H
#define screens_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct registration_login
{
    char name[99];
    char cpf[12];
    char email[100];
    char password[100];
}Login;

char main_menu_screen(void);
void about_screen(void);
void team_screen(void);
char login_screen(void);
void registration_login_screen(void);
bool login_client(void);
char modules_screen(void);
#endif