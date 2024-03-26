#include "logic_menu_client.h"
void logic_menu_client()
{
    char option;
    do
    {
        option = client_menu();
        switch (option)
        {
        case '1':
            register_client_screen();
            break;
        case '2':
            edit_client_screen();

            break;
        case '3':
            delete_client_screen();
            break;
        case '4':
            read_client_screen();
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