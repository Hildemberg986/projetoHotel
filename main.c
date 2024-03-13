#include <stdio.h>
#include <stdlib.h>
#include "screens.h"
#include "logic_main_menu.h"
/////
// Programa principal
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