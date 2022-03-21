/*
** EPITECH PROJECT, 2021
** my_printf_flags.c
** File description:
** flags
*/
#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include <stdlib.h>

int the_good_minus (formats_str array_int, char c, int nbr, int moins);

int zero_positif (formats_str array_int, int *nbr, long temp);

char number_flag_d (formats_str array_int, char c, int *nbr, int temp)
{
    if (array_int.b_zero && !array_int.b_minus) {
        c = '0';
        int k = *nbr;
        array_int.b_plus = zero_positif(array_int, &k, temp);
        *nbr = k;
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

int flag_d (va_list list, formats_str array_int)
{
    int temp = va_arg(list, int), nbr = 0;
    char c = ' ';
    if (array_int.b_number > 0) {
        nbr = ABS_ZERO(array_int.b_number - my_intlen(ABS(temp)));
        number_flag_d (array_int, c, &nbr, temp);
    } else {
        if (temp >= 0 && array_int.b_space && !array_int.b_plus)
            my_putchar(' ');
        if (temp < 0)
            my_putchar('-');
        if (array_int.b_plus && temp > 0)
            my_putchar('+');
    }
    my_putint(ABS(temp));
    the_good_minus(array_int, c, nbr, 1);
    return 1;
}

int not_minus_zero (formats_str array_int, int up)
{
    if (array_int.b_diez) {
        if (up)
            my_putstr("0X");
        else
            my_putstr("0x");
    }
    return 0;
}

int flag_x (va_list list, formats_str array_int, char D)
{
    char *temp = my_long_to_base(va_arg(list, long), 16), c = ' ';
    int up = 0, nbr;
    if (D == 'X') {
        temp = my_strupcase(temp);
        up = 1;
    }
    if (array_int.b_number > 0) {
        nbr = ABS_ZERO(array_int.b_number - my_strlen(temp));
        if (array_int.b_diez)
            nbr -= 2;
        if (array_int.b_zero && !array_int.b_minus) {
            c = '0';
            array_int.b_diez = not_minus_zero(array_int, up);
        }
        the_good_minus(array_int, c, nbr, 0);
        not_minus_zero(array_int, up);
    }
    my_putstr(temp);
    the_good_minus(array_int, c, nbr, 1);
    return 1;
}
