#include <stdio.h>
#include <stdlib.h>
#include "./screens/screens.h"
#include "./logic/logic_main_menu.h"
#include "./screens/client_screens.h"
/////
// Programa principal
Client clients[10];

int main(void)
{
    
    char option;
    do
    {
        option = main_menu_screen();
        logic_main_menu(option);

    } while (option != '0');
    return 0;
}