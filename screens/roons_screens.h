#ifndef roons_screens_H
#define roons_screens_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void register_roons_screen(void);
void edit_roons_screen(void);
void delete_roons_screen(void);
void read_roons_screen(void);
struct register_room
{
    char number[99];
    char type[99];
    char value[99];
    char quantity[99];
};
#endif