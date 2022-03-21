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

int flag_u (va_list list, formats_str array_int)
{
    unsigned int temp = va_arg(list, unsigned int);
    int nbr;
    char c = ' ';
    if (array_int.b_number > 0) {
        nbr = ABS_ZERO(array_int.b_number - my_unsintlen(temp));
        if (array_int.b_zero && !array_int.b_minus)
            c = '0';
        the_good_minus(array_int, c, nbr, 0);
    }
    my_putunsint(temp);
    the_good_minus(array_int, c, nbr, 1);
    return 1;
}

int flag_s (va_list list, formats_str array_int)
{
    char *temp = va_arg(list, char *);
    if (!temp) {
        my_putstr("(null)");
        return 1;
    }
    char c = ' ';
    int nbr;
    if (array_int.b_number > 0) {
        nbr = ABS_ZERO(array_int.b_number - my_strlen(temp));
        the_good_minus(array_int, c, nbr, 0);
    }
    my_putstr(temp);
    the_good_minus(array_int, c, nbr, 1);
    return 1;
}

int flag_c (va_list list, formats_str array_int)
{
    char temp = va_arg(list, int);
    char c = ' ';
    int nbr;
    if (array_int.b_number > 0) {
        nbr = ABS_ZERO(array_int.b_number - 1);
        the_good_minus(array_int, c, nbr, 0);
    }
    my_putchar(temp);
    the_good_minus(array_int, c, nbr, 1);
    return 1;
}

int flag_b (va_list list, formats_str array_int)
{
    char *temp = my_int_to_base(va_arg(list, int), 2);
    char c = ' ';
    int nbr;
    if (array_int.b_number > 0) {
        nbr = ABS_ZERO(array_int.b_number - my_strlen(temp));
        if (array_int.b_zero)
            c = '0';
        the_good_minus(array_int, c, nbr, 0);
    }
    my_putstr(temp);
    the_good_minus(array_int, c, nbr, 1);
    return 1;
}
