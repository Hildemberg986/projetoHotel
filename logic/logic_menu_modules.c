#include "logic_menu_modules.h"

void logic_menu_modules()
{

    char option;
    do
    {
        option = modules_screen();
        switch (option)
        {
        case '1':
            logic_menu_roons();
            break;
        case '2':
            logic_menu_client();
            break;
        case '3':
            logic_menu_reservation();
            break;
        case '0':
            break;
        default:
            system("clear||cls");
            printf("\t\t\tOpção inválida. Tente novamente.\n");
            clean_buffer();
            sleep_code(2);
        }
    } while (option != '0');
}