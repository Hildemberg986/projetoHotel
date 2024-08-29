#ifndef utility_functions_H
#define utility_functions_H
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "./database_functions.h"
typedef struct date
{
    int day;
    int month;
    int year;
}Date;

void sleep_code(int seconds);
void clean_buffer();
bool valida_cpf(const char *imputCPF);
void clear_last_lines(int n);
char read_cpf(char *cpf);
void initial_files();
char* return_end_reservation();
char* read_cpf_Consult();
char* read_room_Consult();
char read_room(char *room_number);
char read_date(char *date, char *texto);
bool valida_data(const char *date);
bool bissexto_year_check(int year);
bool compare_date(char *date_old_primary, char *date_old_secundary, char *date_new_primary, char *date_new_secundary);
int cont_day(Date date);
#endif