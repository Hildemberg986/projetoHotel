#include "reservation_screens.h"

char reservation_menu(void)
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
    Reservation reservation;

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
    strcpy(reservation.room_number, read_room_Consult());
    printf("###   --> Digite o Dia de Entrada... ");
    scanf("%99[^\n]", reservation.day_enter);
    getchar();
    printf("###   --> Digite o Dia de Saida... ");
    scanf("%99[^\n]", reservation.day_exit);
    getchar();
    strcpy(reservation.client_cpf, read_cpf_Consult());
    reservation.del = false;
    char *reservation_number = return_end_reservation();
    strcpy(reservation.reservation_number, reservation_number);
    save_file_reservation(reservation);
    system("clear||cls");
    printf("Reserva Feita Com Sucesso, Número da Reserva %s\n", reservation_number);
    free(reservation_number);
    printf("###   --> Tecle Enter Para Continuar... ");
    getchar();
}

void edit_reservation_screen(void)
{
    char id[12];
    Client *load_client_copy;
    Reservation *load_reservation_copy;
    Reservation reservation;

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
    printf("###   --> Se não Souber o id da Rezerva digite 000 Para sair, Pesquise a Reserva por CPF.\n");
    printf("###   --> Digite o ID da Reserva Para Editar a Reserva... ");
    scanf("%12[^\n]", id);
    getchar();
    load_reservation_copy = search_reservation_id(id);
    if (load_reservation_copy != NULL)
    {
        load_client_copy = search_client_cpf(load_reservation_copy->client_cpf);
        if (load_client_copy != NULL)
        {
            printf("CPF: %s\n", load_reservation_copy->client_cpf);
            printf("Name: %s\n", load_client_copy->name);
            printf("Phone: %s\n", load_client_copy->fone);
            printf("Dia de entrada: %s | Dia de Saída: %s\n", load_reservation_copy->day_enter, load_reservation_copy->day_exit);
            printf("Número Do quarto: %s\n", load_reservation_copy->room_number);

            reservation = *load_reservation_copy;
            // Liberar memória alocada para o cliente
            free(load_client_copy);

            // Preparar nova reserva
            printf("###   --> Digite o Novo Dia de Entrada... ");
            scanf("%99[^\n]", reservation.day_enter);
            getchar();
            printf("###   --> Digite o Novo Dia de Sáida... ");
            scanf("%99[^\n]", reservation.day_exit);
            getchar();

            // Editar reserva
            edit_reservation(*load_reservation_copy, reservation);

            // Liberar memória alocada para a reserva
            free(load_reservation_copy);
        }
        else
        {
            printf("Cliente Não Encontrado.\n");
            free(load_reservation_copy);
            sleep_code(2);
        }
    }
    else if (strcmp(id, "000") != 0)
    {
        printf("Saindo...\n");
        sleep_code(2);
    }
}
void delete_reservation_screen(void)
{
    char quest[3];
    Client *load_client_copy;
    Reservation *load_reservation_copy;
    Reservation reservation;

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
    printf("###   --> Digite o ID da Reserva Para Excluir Reserva... ");
    scanf("%12[^\n]", reservation.reservation_number);
    getchar();
    load_reservation_copy = search_reservation_id(reservation.reservation_number);
    if (load_reservation_copy != NULL)
    {

        load_client_copy = search_client_cpf(load_reservation_copy->client_cpf);
        if (load_client_copy != NULL)
        {
            // Use a variável load_client_copy, por exemplo, imprimindo seus dados
            printf("ID da Reserva: %s\n", load_reservation_copy->reservation_number);
            printf("CPF: %s\n", load_client_copy->cpf);
            printf("Name: %s\n", load_client_copy->name);
            printf("Phone: %s\n", load_client_copy->fone);
            printf("Dia de Entrada: %s || Dia de Saida: %s \n", load_reservation_copy->day_enter, load_reservation_copy->day_exit);

            // Pergunta se o usuário deseja excluir o cliente
            printf("Deseja Realmente Excluir Essa Reserva? (s/n): ");
            fgets(quest, sizeof(quest), stdin);
            quest[strcspn(quest, "\n")] = '\0'; // Remove o '\n' final
            free(load_client_copy);
            if ((strcmp(quest, "s") == 0) || (strcmp(quest, "S") == 0))
            {
                // Atualiza os dados da reserva
                reservation = *load_reservation_copy;
                reservation.del = true;
                edit_reservation(*load_reservation_copy, reservation);
                free(load_reservation_copy);
                system("clear||cls");
                printf("Exclusão bem Sucedida!");
                sleep_code(2);
            }
            else
            {
                system("clear||cls");
                printf("Exclusão cancelada.\n");
                sleep_code(2);
                free(load_reservation_copy);
            }
        }
    }
    else
    {
        free(load_reservation_copy);
        printf("Cliente não encontrado.\n");
        sleep_code(2);
    }
}
void read_reservation_screen(void)
{
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
    printf("###                    |=====- Pesquisar Reserva -=====|                    ###\n");
    printf("###                                                                         ###\n");
    printf("###   --> Digite o CPF da pessoa para Pesquisar as Reservas... ");
    scanf("%12[^\n]", cpf);
    getchar();
    system("clear||cls");
    search_reservation_cpf(cpf);
    clear_last_lines(1);
    getchar();
}