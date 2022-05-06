/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** my_itoa
*/

#include "my.h"

char *my_itoa(int nb)
{
    int count = 1;
    int i = nb;
    while (i >= 10) {
        i = i / 10;
        count += 1;
    }
    char *str = malloc(sizeof(char) * count + 1);
    i = count - 1;
    while (i >= 0) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
        i = i - 1;
    }
    str[count] = '\0';
    return (str);
}
