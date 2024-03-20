#include "logic_menu_reservation.h"
void logic_menu_reservation()
{
    char option;
    do
    {
        option = reservation_menu();
        switch (option)
        {
        case '1':
            register_reservation_screen();
            break;
        case '2':
            edit_reservation_screen();
            break;
        case '3':
            delete_reservation_screen();
            break;
        case '4':
            read_reservation_screen();
            break;
        case '0':
            break;
        default:
            printf("\t\t\tOpção inválida. Tente novamente.\n");
        }
    } while (option != '0');
}