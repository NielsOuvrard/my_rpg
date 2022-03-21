/*
** EPITECH PROJECT, 2021
** my_int_to_str.c
** File description:
** my_int_to_str
*/
#include "my.h"
#include <stdlib.h>

char *my_int_to_str(int nb)
{
    if (nb == 0)
        return "0\0";
    int i = my_intlen(nb), j = 0, t = 0;
    char *str = malloc(sizeof(char) * (i + 2));
    if (nb < 0) {
        nb = -nb;
        t++;
    }
    for (; j < i; j++) {
        str[j] = (nb % 10) + '0';
        nb = nb / 10;
    }
    if (t == 1)
        str[j++] = '-';
    str[j] = '\0';
    str = my_revstr(str);
    return (str);
}
