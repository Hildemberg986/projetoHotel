#include "client_screens.h"

void register_client_screen(void)
{
    struct register_client pessoa;

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
    printf("###                        |=====- Cadastro -=====|                         ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o Nome do Cliente... ");
    scanf("%99[^\n]", pessoa.name);
    getchar();
    printf("###   --> Digite o CPF do Cliente... ");
    scanf("%12[^\n]", pessoa.cpf);
    getchar();
    printf("###   --> Digite o telefone do Cliente... ");
    scanf("%100[^\n]", pessoa.fone);
    getchar();
    printf("\n");
}