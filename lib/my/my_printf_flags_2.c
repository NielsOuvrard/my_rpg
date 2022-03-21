/*
** EPITECH PROJECT, 2021
** my_printf_flags2.c
** File description:
** flags 2
*/
#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include <stdlib.h>

int the_good_minus (formats_str array_int, char c, int nbr, int moins);

int zero_positif (formats_str array_int, int *nbr, long temp)
{
    if (array_int.b_plus && temp > 0) {
        my_putchar('+');
        (*nbr)--;
    } else if (temp < 0) {
        my_putchar('-');
        (*nbr)--;
    }
    return 0;
}

char number_flag_l (formats_str array_int, char c, int *nbr, long temp)
{
    if (array_int.b_zero && !array_int.b_minus) {
        int k = *nbr;
        array_int.b_plus = zero_positif(array_int, &k, temp);
        *nbr = k;
        c = '0';
    } else if (temp < 0 && !array_int.b_plus) {
        (*nbr)--;
    }
    if (array_int.b_space && !array_int.b_plus && !array_int.b_zero) {
        my_putchar(' ');
        (*nbr)--;
    }
    if (array_int.b_plus)
        (*nbr)--;
    the_good_minus(array_int, c, *nbr, 0);
    if (array_int.b_plus && temp > 0)
        my_putchar('+');
    else if (temp < 0 && !array_int.b_zero)
        my_putchar('-');
    return c;
}

int flag_l (va_list list, formats_str array_int)
{
    long temp = va_arg(list, long);
    int nbr = 0;
    char c = ' ';
    if (array_int.b_number > 0) {
        nbr = ABS_ZERO(array_int.b_number - my_longlen(ABS(temp)));
        number_flag_l(array_int, c, &nbr, temp);
    } else {
        if (temp >= 0 && array_int.b_space && !array_int.b_plus)
            my_putchar(' ');
        if (temp < 0)
            my_putchar('-');
        if (array_int.b_plus && temp > 0)
            my_putchar('+');
    }
    my_putlong(ABS(temp));
    the_good_minus(array_int, c, nbr, 1);
    return 1;
}
