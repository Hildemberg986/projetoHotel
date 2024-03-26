#include "utility_functions.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Retirado do chatGPT
void clean_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void sleep_code(int seconds)
{
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif
}