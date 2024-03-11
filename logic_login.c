#include "logic_login.h"

void logic_login()
{
    char option;
    do
    {
        option = login_screen();
        switch (option)
        {
        case '1':
            login_client();
            break;
        case '2':
            registration_screen();
            break;
        case '0':
            break;
        default:
            printf("\t\t\tOpção inválida. Tente novamente.\n");
        }
    } while (option != '0');
}