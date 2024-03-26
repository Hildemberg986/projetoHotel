#include "reservation_screens.h"

char reservation_menu(void){
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
    printf("###                     |=====- Menu  Reservas -=====|                      ###\n");
    printf("###                                                                         ###\n");
    printf("###                          1-> Cadastrar Reserva                          ###\n");
    printf("###                          2-> Editar Reserva                             ###\n");
    printf("###                          3-> Excluir Reserva                            ###\n");
    printf("###                          4-> Pesquisar Reserva                          ###\n");
    printf("###                          0-> Sair                                       ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("###  Digite a opção desejada e Tecle <ENTER> para continuar... ");
    scanf(" %c", &option);
    getchar();
    return option;
}

void register_reservation_screen(void)
{
    struct register_reservation reservation;

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
    printf("###                   |=====- Cadastro de Reserva -=====|                   ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o Numero do Quarto a Ser Reservado... ");
    scanf("%99[^\n]", reservation.number);
    getchar();
    printf("###   --> Digite o Dia de Entrada... ");
    scanf("%99[^\n]", reservation.day_enter);
    getchar();
    printf("###   --> Digite o Dia de Saida... ");
    scanf("%99[^\n]", reservation.day_exit);
    getchar();
    printf("###   --> Digite o CPF do Cliente Que Reservou... ");
    scanf("%99[^\n]", reservation.client_cpf);
    getchar();
    printf("\n");
}

void edit_reservation_screen(void)
{
    struct register_reservation reservation;

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
    printf("###                     |=====- Editar Reserva -=====|                      ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o CPF do Cliente Para Ver as Reservas... ");
    scanf("%12[^\n]", reservation.client_cpf);
    getchar();
}
void delete_reservation_screen(void)
{
    struct register_reservation reservation;

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
    printf("###                     |=====- Excluir Reserva -=====|                     ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o CPF do Cliente Para Ver as Reservas... ");
    scanf("%12[^\n]", reservation.client_cpf);
    getchar();
}
void read_reservation_screen(void)
{
    struct register_reservation reservation;

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
    printf("###                    |=====- Pesquisar Reserva -=====|                    ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o Numero do Quarto para Pesquisar as Reservas... ");
    scanf("%12[^\n]", reservation.number);
    getchar();
}