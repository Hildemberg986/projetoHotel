#include "logic_login.h"

void logic_login()
{
    bool validation = true;

    char option;
    do
    {
        option = login_screen();
        switch (option)
        {
        case '1':
            login_client();
            if (validation)
            {
                logic_menu_modules();
            }

            break;
        case '2':
            registration_login_screen();
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