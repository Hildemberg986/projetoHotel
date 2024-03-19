#include "roons_screens.h"

char room_menu(void){
    char option;
    system("clear||cls");
    printf("\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte                 ###\n");
    printf("###                 Centro de Ensino Superior do Seridó                     ###\n");
    printf("###               Departamento de Computação e Tecnologia                   ###\n");
    printf("###                  Disciplina DCT1106 -- Programação                      ###\n");
    printf("###             Projeto Um Sistema de Gestão para um Hotel                  ###\n");
    printf("###    Developed by https://github.com/Hildemberg986 -- since Mar, 2024     ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###                      |=====- Menu  Quartos -=====|                      ###\n");
    printf("###                                                                         ###\n");
    printf("###                          1-> Cadastrar Quarto                           ###\n");
    printf("###                          2-> Editar Quarto                              ###\n");
    printf("###                          3-> Excluir Quarto                             ###\n");
    printf("###                          4-> Pesquisar Quarto                           ###\n");
    printf("###                          0-> Sair                                       ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("###  Digite a opção desejada e Tecle <ENTER> para continuar... ");
    scanf(" %c", &option);
    getchar();
    return option;
}

void register_roons_screen(void)
{
    struct register_room room;

    system("clear||cls");
    printf("\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte                 ###\n");
    printf("###                 Centro de Ensino Superior do Seridó                     ###\n");
    printf("###               Departamento de Computação e Tecnologia                   ###\n");
    printf("###                  Disciplina DCT1106 -- Programação                      ###\n");
    printf("###             Projeto Um Sistema de Gestão para um Hotel                  ###\n");
    printf("###    Developed by https://github.com/Hildemberg986 -- since Mar, 2024     ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                     |=====- Cadastro Quarto -=====|                     ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o Numero do Quarto... ");
    scanf("%99[^\n]", room.number);
    getchar();
    printf("###   --> Digite o Tipo do Quarto... ");
    scanf("%99[^\n]", room.type);
    getchar();
    printf("###   --> Digite o valor do Quarto... ");
    scanf("%99[^\n]", room.value);
    getchar();
    printf("###   --> Digite a Quantidade de Pessoas Que o Quarto Comporta... ");
    scanf("%99[^\n]", room.quantity);
    getchar();
    printf("\n");
}

void edit_roons_screen(void)
{
    struct register_room room;

    system("clear||cls");
    printf("\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte                 ###\n");
    printf("###                 Centro de Ensino Superior do Seridó                     ###\n");
    printf("###               Departamento de Computação e Tecnologia                   ###\n");
    printf("###                  Disciplina DCT1106 -- Programação                      ###\n");
    printf("###             Projeto Um Sistema de Gestão para um Hotel                  ###\n");
    printf("###    Developed by https://github.com/Hildemberg986 -- since Mar, 2024     ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###                     |=====- Editar Quarto -=====|                       ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o Numero do Quarto para Editar... ");
    scanf("%12[^\n]", room.number);
    getchar();
}
void delete_roons_screen(void)
{
    struct register_room room;

    system("clear||cls");
    printf("\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte                 ###\n");
    printf("###                 Centro de Ensino Superior do Seridó                     ###\n");
    printf("###               Departamento de Computação e Tecnologia                   ###\n");
    printf("###                  Disciplina DCT1106 -- Programação                      ###\n");
    printf("###             Projeto Um Sistema de Gestão para um Hotel                  ###\n");
    printf("###    Developed by https://github.com/Hildemberg986 -- since Mar, 2024     ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###                     |=====- Excluir Quarto -=====|                      ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o Numero do Quarto para Excluir... ");
    scanf("%12[^\n]", room.number);
    getchar();
}
void read_roons_screen(void)
{
    struct register_room room;

    system("clear||cls");
    printf("\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte                 ###\n");
    printf("###                 Centro de Ensino Superior do Seridó                     ###\n");
    printf("###               Departamento de Computação e Tecnologia                   ###\n");
    printf("###                  Disciplina DCT1106 -- Programação                      ###\n");
    printf("###             Projeto Um Sistema de Gestão para um Hotel                  ###\n");
    printf("###    Developed by https://github.com/Hildemberg986 -- since Mar, 2024     ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###                    |=====- Pesquisar Quarto -=====|                     ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o Numero do Quarto para Pesquisar... ");
    scanf("%12[^\n]", room.number);
    getchar();
}