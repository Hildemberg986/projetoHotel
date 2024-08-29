#ifndef utility_functions_H
#define utility_functions_H
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "./database_functions.h"
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
#endif