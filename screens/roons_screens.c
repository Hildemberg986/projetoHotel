#include "roons_screens.h"

char room_menu(void)
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
    Room room;

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
    read_room(room.number);
    printf("###   --> Digite o Tipo do Quarto... ");
    scanf("%99[^\n]", room.type);
    getchar();
    printf("###   --> Digite o valor do Quarto... ");
    scanf("%99[^\n]", room.value);
    getchar();
    printf("###   --> Digite a Quantidade de Pessoas Que o Quarto Comporta... ");
    scanf("%99[^\n]", room.quantity);
    save_file_room(room);
    getchar();
    printf("\n");
}

void edit_roons_screen(void)
{
    Room *load_room_copy;
    Room room;

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
    load_room_copy = search_room(room.number);
    if (load_room_copy != NULL)
    {

        printf("Nùmero do Quarto: %s\n", load_room_copy->number);
        printf("Quantidade de Pessoas no Quarto: %s\n", load_room_copy->quantity);
        printf("Tipo do Quarto: %s\n", load_room_copy->type);
        printf("Valor Do Quarto: %s\n", load_room_copy->value);

        room = *load_room_copy;

        // Preparar nova reserva
        printf("###   --> Digite a Nova Quantidade de Pessoas para o Quarto... ");
        scanf("%99[^\n]", room.quantity);
        getchar();
        printf("###   --> Digite o Novo Tipo do Quarto... ");
        scanf("%99[^\n]", room.type);
        getchar();
        printf("###   --> Digite o Novo Valor do Quarto... ");
        scanf("%99[^\n]", room.value);
        getchar();

        // Editar reserva
        edit_room(*load_room_copy, room);

        // Liberar memória alocada para a reserva
        free(load_room_copy);
    }
}
void delete_roons_screen(void)
{
    char quest[3];
    Room *load_room_copy;
    Room room;

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
    load_room_copy = search_room(room.number);
    if (load_room_copy != NULL)
    {

        printf("Nùmero do Quarto: %s\n", load_room_copy->number);
        printf("Quantidade de Pessoas no Quarto: %s\n", load_room_copy->quantity);
        printf("Tipo do Quarto: %s\n", load_room_copy->type);
        printf("Valor Do Quarto: %s\n", load_room_copy->value);

        printf("Deseja Realmente Excluir Esse Quarto? (s/n): ");
        fgets(quest, sizeof(quest), stdin);
        quest[strcspn(quest, "\n")] = '\0'; // Remove o '\n' final

        if ((strcmp(quest, "s") == 0) || (strcmp(quest, "S") == 0))
        {
            // Atualiza os dados da reserva
            room = *load_room_copy;
            room.del = true;
            edit_room(*load_room_copy, room);
            free(load_room_copy);
            system("clear||cls");
            printf("Exclusão bem Sucedida!");
            sleep_code(2);
        }
        else
        {
            system("clear||cls");
            printf("Exclusão cancelada.\n");
            sleep_code(2);
            free(load_room_copy);
        }
    }
}

void read_roons_screen(void)
{
    Room *load_room_copy = NULL;
    char number[99];

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
    scanf("%99[^\n]", number);
    getchar();
    load_room_copy = search_room(number);
    if (load_room_copy != NULL)
    {
        // Use a variável load_room_copy, por exemplo, imprimindo seus dados
        printf("Numero do quarto: %s\n", load_room_copy->number);
        printf("Quantidade de pessoas no quarto: %s\n", load_room_copy->quantity);
        printf("Tipo do quarto: %s\n", load_room_copy->type);
        printf("Valor do quarto: %s\n", load_room_copy->value);
        getchar();
        free(load_room_copy);
    }
    else
    {
        system("clear||cls");
        printf("Quarto não encontrado!\n");
        sleep_code(2);
    }
}