#include "logic_client.h"

void logic_client()
{

    char option;
    do
    {   
        printf("\t\t\tOpção inválida. Tente novamente.\n");
        option = login_screen_client();
        switch (option)
        {
        case '1':
            register_client_screen();
            break;
        case '2':
            break;
        case '0':
            break;
        default:
            printf("\t\t\tOpção inválida. Tente novamente.\n");
        }
    } while (option != '0');
}