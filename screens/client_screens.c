#include "client_screens.h"
char client_menu(void)
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

void register_client_screen(void)
{
    Client pessoa;

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
    printf("###                    |=====- Cadastro Cliente -=====|                     ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o Nome do Cliente... ");
    scanf("%99[^\n]", pessoa.name);
    getchar();
    read_cpf(pessoa.cpf);
    printf("###   --> Digite o telefone do Cliente... ");
    scanf("%100[^\n]", pessoa.fone);
    getchar();
    save_file_client(pessoa);
}

void edit_client_screen(void)
{
    char cpf[12];
    Client *load_client_copy;
    Client pessoa;

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
    printf("###                   |=====- Edição de Cliente -=====|                     ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o CPF do Cliente para Editar... ");
    scanf("%12[^\n]", cpf);
    getchar();
    load_client_copy = search_client_cpf(cpf);
    if (load_client_copy != NULL)
    {
        // Use a variável load_client_copy, por exemplo, imprimindo seus dados
        printf("CPF: %s\n", load_client_copy->cpf);
        printf("Name: %s\n", load_client_copy->name);
        printf("Phone: %s\n", load_client_copy->fone);
        free(load_client_copy);
    }
    else
    {
        printf("Client not found or memory allocation failed.\n");
    }
    getchar();
    
    printf("###   --> Digite o Novo Nome do Cliente... ");
    scanf("%99[^\n]", pessoa.name);
    getchar();
    read_cpf(pessoa.cpf);
    printf("###   --> Digite o Novo Telefone do Cliente... ");
    scanf("%100[^\n]", pessoa.fone);
    getchar();
    edit_client(*load_client_copy, pessoa);
}
void delete_client_screen(void)
{
    Client pessoa;

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
    printf("###                  |=====- Exclusão de Cliente -=====|                    ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o CPF do Cliente para Excluir... ");
    scanf("%12[^\n]", pessoa.cpf);
    getchar();
}
void read_client_screen(void)
{
    Client *load_client_copy;

    char cpf[12];

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
    printf("###                  |=====- Pesquisa de Cliente -=====|                    ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o CPF do Cliente para Pesquisar... ");
    scanf("%12[^\n]", cpf);
    getchar();
    load_client_copy = search_client_cpf(cpf);
    if (load_client_copy != NULL)
    {
        // Use a variável load_client_copy, por exemplo, imprimindo seus dados
        printf("CPF: %s\n", load_client_copy->cpf);
        printf("Name: %s\n", load_client_copy->name);
        printf("Phone: %s\n", load_client_copy->fone);
        free(load_client_copy);
    }
    else
    {
        printf("Client not found or memory allocation failed.\n");
    }
    getchar();
}