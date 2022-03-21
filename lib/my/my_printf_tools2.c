/*
** EPITECH PROJECT, 2021
** my_printf_tools2.c
** File description:
** my_printf, les outils nbr 2
*/
#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include <stdlib.h>

int flag_d (va_list list, formats_str array_int);

int flag_x (va_list list, formats_str array_int, char c);

int flag_o (va_list list, formats_str array_int);

int flag_b (va_list list, formats_str array_int);

int flag_p (va_list list, formats_str array_int);

int flag_l (va_list list, formats_str array_int);

int flag_u (va_list list, formats_str array_int);

int flag_s (va_list list, formats_str array_int);

int flag_c (va_list list, formats_str array_int);

int is_a_flag (char *str, int a)
{
    if (str[a] == 'd' || str[a] == 'i' || str[a] == 'x' || str[a] == 'X')
        return 1;
    if (str[a] == 'o' || str[a] == 'c' || str[a] == 's' || str[a] == 'p')
        return 1;
    if (str[a] == 'u' || str[a] == 'S' || str[a] == 'b')
        return 1;
    if (str[a + 1] != '\0' && (str[a] == 'l' || str[a] == 'h') &&
    (str[a + 1] == 'd' || str[a + 1] == 'i'))
        return 1;
    return 0;
}

int the_good_minus (formats_str array_int, char c, int nbr, int moins)
{
    if (!array_int.b_minus && !moins)
        for (int a = 0; a < nbr; a++)
            my_putchar(c);
    if (array_int.b_minus && moins)
        for (int a = 0; a < nbr; a++)
            my_putchar(c);
    return 0;
}

int swich_to_funct3 (va_list list, formats_str array_int, char c)
{
    switch (c) {
        case 'c':
            flag_c(list, array_int);
            return 1;
        case 'h':
            flag_d(list, array_int);
            return 1;
        case 'u':
            flag_u(list, array_int);
            return 1;
    }
    return 0;
}

int swich_to_funct2 (va_list list, formats_str array_int, char c)
{
    switch (c) {
        case 'o':
            flag_o(list, array_int);
            return 1;
        case 'b':
            flag_b(list, array_int);
            return 1;
        case 'S':
            my_put_str_oct(va_arg(list, char *));
            return 1;
        case 'p':
            flag_p(list, array_int);
            return 1;
        case 'l':
            flag_l(list, array_int);
            return 1;
    }
    return swich_to_funct3(list, array_int, c);
}

int swich_to_funct (va_list list, formats_str array_int, char c)
{
    switch (c) {
        case 's':
            flag_s(list, array_int);
            return 1;
        case 'd':
            flag_d(list, array_int);
            return 1;
        case 'i':
            flag_d(list, array_int);
            return 1;
        case 'x':
            flag_x(list, array_int, c);
            return 1;
        case 'X':
            flag_x(list, array_int, c);
            return 1;
    }
    return swich_to_funct2(list, array_int, c);
}
