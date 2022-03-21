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

int dize_flag_o (formats_str array_int)
{
    if (array_int.b_diez)
        my_putstr("0");
    return 0;
}

int flag_o (va_list list, formats_str array_int)
{
    unsigned long long value = va_arg(list, unsigned long long);
    char *temp = my_long_to_base(value, 8);
    int nbr;
    char c = ' ';
    if (array_int.b_number > 0) {
        nbr = ABS_ZERO(array_int.b_number - my_strlen(temp));
        if (array_int.b_diez)
            nbr--;
        if (array_int.b_zero && !array_int.b_minus) {
            c = '0';
            array_int.b_diez = dize_flag_o(array_int);
        }
        the_good_minus(array_int, c, nbr, 0);
    }
    dize_flag_o(array_int);
    my_putstr(temp);
    the_good_minus(array_int, c, nbr, 1);
    return 1;
}

char number_flag_p (formats_str array_int, int *nbr, char c, char *temp2)
{
    *nbr = ABS_ZERO(array_int.b_number - my_strlen(temp2) - 2);
    if (array_int.b_zero && !array_int.b_minus)
        c = '0';
    if (array_int.b_plus)
        (*nbr)--;
    the_good_minus(array_int, c, *nbr, 0);
    if (array_int.b_plus)
        my_putchar('+');
    return c;
}

int flag_p (va_list list, formats_str array_int)
{
    void *temp = va_arg(list, void *);
    char *temp2 = my_long_to_base((long)temp, 16);
    char c = ' ';
    int nbr = 0;
    if (array_int.b_number > 0) {
        c = number_flag_p(array_int, &nbr, c, temp2);
    } else {
        if (array_int.b_plus)
            my_putchar('+');
    }
    if (array_int.b_space && !array_int.b_plus && !array_int.b_zero) {
        my_putchar(' ');
        nbr--;
    }
    my_putstr("0x");
    my_putstr(temp2);
    the_good_minus(array_int, c, nbr, 1);
    return 1;
}
