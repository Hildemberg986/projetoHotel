#ifndef utility_functions_H
#define utility_functions_H
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
void sleep_code(int seconds);
void clean_buffer();
bool valida_cpf(const char *imputCPF);
void clear_last_lines(int n);
char read_cpf(char *cpf);
#endif