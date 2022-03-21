/*
** EPITECH PROJECT, 2021
** my_show_word_array.c
** File description:
** my show word array
*/
#include <stdlib.h>

int my_putstr (char *str);

int my_putchar (char c);

int my_show_word_array (char * const *tab)
{
    int incr = 0;
    while (tab[incr] != NULL) {
        my_putstr(tab[incr]);
        my_putchar('\n');
        incr++;
    }
    return 0;
}
