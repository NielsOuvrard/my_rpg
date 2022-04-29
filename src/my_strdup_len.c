/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** my_strdup_len
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup_to (char const *src, int len)
{
    int lengh_src = len + 1;
    char *str = malloc(sizeof(char) * my_strlen(src) + 1);
    str[lengh_src] = '\0';
    int i = 0;
    while (i != lengh_src) {
        str[i] = src[i];
        i++;
    }
    return str;
}
