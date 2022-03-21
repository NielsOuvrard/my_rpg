/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf.c
*/
#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include <stdlib.h>

int is_a_flag (char *str, int a);

formats_str alanyse_formats (char *str, int a, char *formats);

int swich_to_funct (va_list list, formats_str array_int, char c);

char *check_format_2 (char *str, int *a, int retour)
{
    int w, t, f, plus_post_sp = 0, boolean_space = 0;
    for (w = 0; !my_isalpha(str[*a + w]); w++);
    char *formats = malloc(sizeof(char) * w + 1);
    char *if_erreur = malloc(sizeof(char) * w + 1);
    for (f = 0, t = 0; w > t; t++) {
        if (str[*a + t] != ' ')
            formats[f++] = str[*a + t];
        if (str[*a + t] == ' ' && !boolean_space) {
            boolean_space = 1;
            formats[f++] = str[*a + t];
        }
        if_erreur[t] = str[*a + t];
    }
    formats[f] = '\0';
    *a += --t;
    if (retour)
        return formats;
    return if_erreur;
}

void check_format (va_list list, char *str, int *a)
{
    int b = *a, k = *a;
    char *if_erreur = check_format_2(str, &b, 0);
    char *formats = check_format_2(str, &k, 1);
    *a = k;
    formats_str array_int = alanyse_formats(str, *a, formats);
    if (array_int.error) {
        my_putchar('%');
        my_putstr(if_erreur);
        return;
    }
    char c = str[++(*a)];
    if (is_a_flag(str, *a))
        swich_to_funct(list, array_int, c);
    if (str[(*a)] == 'l' || str[(*a)] == 'h')
        (*a)++;
}

int my_printf (char * str, ... )
{
    int return_value = 0, a;
    va_list list;
    va_start(list, str);
    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] == '%' && str[a + 1] != '\0' && str[a + 1] != '%') {
            a++;
            check_format(list, str, &a);
        } else if (str[a] == '%' && str[a + 1] != '\0' && str[a + 1] == '%') {
            my_putchar('%');
            a++;
        } else {
            my_putchar(str[a]);
            return_value++;
        }
    }
    va_end(list);
    return return_value;
}
