/*
** EPITECH PROJECT, 2021
** my_printf_tools.c
** File description:
** my_printf, les outils
*/
#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include <stdlib.h>

formats_str creat_array_int (void)
{
    formats_str array_int;
    array_int.b_zero = 0;
    array_int.b_number = 0;
    array_int.b_diez = 0;
    array_int.b_plus = 0;
    array_int.b_minus = 0;
    array_int.b_space = 0;
    array_int.b_point = 0;
    array_int.error = 0;
    return array_int;
}

int my_isnbr_neg(char a)
{
    if ((a >= '0' && '9' >= a) || a == '-')
        return 1;
    return 0;
}

int funct_af (char *str, int *q, char *formats)
{
    int nbr = 0, returned;
    char *temp = malloc(sizeof(char) * my_strlen(str) + 1);
    while (my_isnbr_neg(formats[*q + nbr])) {
        temp[nbr] = formats[*q + nbr];
        nbr++;
    }
    temp[nbr] = '\0';
    returned = my_getnbr(temp);
    free(temp);
    *q += --nbr;
    return returned;
}

formats_str classiqes_formats (char *formats, int q, formats_str array_int)
{
    if (formats[q] == ' ')
        array_int.b_space = 1;
    else if (formats[q] == '+')
        array_int.b_plus = 1;
    if (formats[q] == '-')
        array_int.b_minus = 1;
    else if (formats[q] == '#')
        array_int.b_diez = 1;
    return array_int;
}

formats_str alanyse_formats (char *str, int a, char *formats)
{
    formats_str array_int = creat_array_int();
    array_int.b_number = 0;
    for (int q = 0; formats[q] != '\0'; q++) {
        array_int = classiqes_formats(formats, q, array_int);
        if (!array_int.b_number && formats[q] == '0')
            array_int.b_zero = 1;
        if (my_isdidgit(formats[q])) {
            array_int.b_number = funct_af(str, &q, formats);
        }
        if (array_int.b_number > 0 && (formats[q] == '-' || formats[q] == '+'
        || formats[q] == ' ' || formats[q] == '#'))
            array_int.error = 1;
    }
    return array_int;
}
