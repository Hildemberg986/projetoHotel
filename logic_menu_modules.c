#include "logic_menu_modules.h"

void logic_menu_modules()
{

    char option;
    do
    {
        option = login_screen_client();
        switch (option)
        {
        case '1':
            break;
        case '2':
            logic_menu_client();
            break;
        case '0':
            break;
        default:
            printf("\t\t\tOpção inválida. Tente novamente.\n");
        }
    } while (option != '0');
}
