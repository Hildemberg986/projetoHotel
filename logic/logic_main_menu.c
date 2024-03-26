#include "logic_main_menu.h"

void logic_main_menu(char option)
{
    switch (option)
    {
    case '1':
        logic_login();
        break;
    case '2':
        about_screen();
        break;
    case '3':
        team_screen();
        break;
    case '0':
        system("clear||cls");
        printf("\t\t\tPrograma Encerrado\n");
        break;
    default:
        system("clear||cls");
        printf("\t\t\tOpção inválida. Tente novamente.\n");
        clean_buffer();
        sleep_code(2);
    }
}