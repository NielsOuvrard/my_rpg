/*
** EPITECH PROJECT, 2021
** my_put_str_oct
** File description:
** my_put_str_oct
*/
#include "my.h"
#include <stdlib.h>

void my_put_str_oct_funct (char *off, char *oct)
{
    for (int t = 0; t < my_strlen(off); t++) {
        oct[t] = off[t];
    }
    return;
}

int my_put_str_oct (char *str)
{
    int result = 0;
    for (int k = 0; str[k] != '\0'; k++){
        if (str[k] < 32 || str[k] >= 127) {
            char *oct = malloc(sizeof(char) * 5);
            oct[4] = '\0';
            oct = my_memset(oct, 3, '0');
            char *off = my_int_to_base(str[k], 8);
            my_revstr(off);
            my_put_str_oct_funct(off, oct);
            my_revstr(oct);
            my_putchar('\\');
            my_putstr(oct);
            result += 4;
        } else {
            my_putchar(str[k]);
            result++;
        }
    }
    return result;
}
