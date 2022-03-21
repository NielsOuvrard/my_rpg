/*
** EPITECH PROJECT, 2021
** my_int_to_hexa.c
** File description:
** my_int_to_hexa
*/
#include "my.h"
#include <stdlib.h>

char *my_int_to_base (int nbr, int base)
{
    int size = my_intlen(nbr), a;
    if (base < 10)
        size *= 10;
    char *result = malloc(sizeof(char) * size + 1);
    for (a = 0; nbr > 0; a++) {
        if (nbr % base < 10) {
            result[a] = ITOC(nbr % base);
        } else {
            result[a] = nbr % base + 87;
        }
        nbr /= base;
    }
    result[a] = '\0';
    my_revstr(result);
    return result;
}
