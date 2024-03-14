#include "screens.h"

char main_menu_screen(void)
{
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
    printf("###                          |=====- Menu -=====|                           ###\n");
    printf("###                                                                         ###\n");
    printf("###                          1-> Login                                      ###\n");
    printf("###                          2-> Sobre                                      ###\n");
    printf("###                          3-> Equipe                                     ###\n");
    printf("###                          0-> Sair                                       ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("###  Digite a opção desejada e Tecle <ENTER> para continuar... ");
    scanf(" %c", &option);
    getchar();
    return option;
}

void about_screen(void)
{
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
    printf("###                         |=====- Sobre -=====|                           ###\n");
    printf("###                                                                         ###\n");
    printf("###  Um  Sistema  comercial  para a  gestão de  um hotel. Desenvolvido  na  ###\n");
    printf("###  materia  DCT1106 - PROGRAMAÇÃO com  o  intuito  avaliativo  sobre  os  ###\n");
    printf("###  alunos para testar a compreenção e conhecimentos  em  programação  do  ###\n");
    printf("###  desenvolvedor, tendo uma natureza estritamente acadêmica.              ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void team_screen(void)
{
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
    printf("###                         |=====- Equipe -=====|                          ###\n");
    printf("###                                                                         ###\n");
    printf("###            Este projeto exemplo foi desenvolvido por:                   ###\n");
    printf("###                                                                         ###\n");
    printf("###            Hildemberg Eling de Araújo Lucena                            ###\n");
    printf("###            E-mail: hildembergeling@gmail.com                            ###\n");
    printf("###            Redes sociais: @hildembergeling                              ###\n");
    printf("###            Git: https://github.com/Hildemberg986                        ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

char login_screen(void)
{
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
    printf("###                     |=====- Menu de Login -=====|                       ###\n");
    printf("###                                                                         ###\n");
    printf("###                       1-> Fazer Login                                   ###\n");
    printf("###                       2-> Cadastrar Novo login                          ###\n");
    printf("###                       0-> Voltar                                        ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("###  Digite a opção desejada e Tecle <ENTER> para continuar... ");
    scanf(" %c", &option);
    getchar();
    return option;
}

void registration_login_screen(void)
{
    struct registration_login pessoa;

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
    printf("###   --> Digite o email do Cliente... ");
    scanf("%100[^\n]", pessoa.email);
    getchar();
    printf("###   --> Digite uma senha de login... ");
    scanf("%12[^\n]", pessoa.password);
    getchar();
    printf("\n");
}

bool login_client(void)
{

    char password[100];
    char cpf[12];
    bool valitation = false;

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
    printf("###                         |=====- Login -=====|                           ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o CPF do Cliente... ");
    scanf("%12[^\n]", cpf);
    getchar();
    printf("###   --> Digite a senha... ");
    scanf("%99[^\n]", password);
    getchar();
    printf("\n");
    return valitation;
}

char login_screen_client(void)
{
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
    printf("###                     |=====- Menu de Modulos -=====|                     ###\n");
    printf("###                                                                         ###\n");
    printf("###                       1-> Quartos                                       ###\n");
    printf("###                       2-> Clientes                                      ###\n");
    printf("###                       3-> Reservas                                      ###\n");
    printf("###                       0-> Voltar                                        ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("###  Digite a opção desejada e Tecle <ENTER> para continuar... ");
    scanf(" %c", &option);
    getchar();
    return option;
}
char client_menu(void){
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
    printf("###                      |=====- Menu  Cliente -=====|                      ###\n");
    printf("###                                                                         ###\n");
    printf("###                          1-> Cadastrar Cliente                          ###\n");
    printf("###                          2-> Editar Cliente                             ###\n");
    printf("###                          3-> Excluir Cliente                            ###\n");
    printf("###                          4-> Pesquisar Cliente                          ###\n");
    printf("###                          0-> Sair                                       ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("###  Digite a opção desejada e Tecle <ENTER> para continuar... ");
    scanf(" %c", &option);
    getchar();
    return option;
}