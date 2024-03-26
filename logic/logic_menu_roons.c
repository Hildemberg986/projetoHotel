#include "logic_menu_roons.h"
void logic_menu_roons()
{
    char option;
    do
    {
        option = room_menu();
        switch (option)
        {
        case '1':
            register_roons_screen();
            break;
        case '2':
            edit_roons_screen();
            break;
        case '3':
            delete_roons_screen();
            break;
        case '4':
            read_roons_screen();
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