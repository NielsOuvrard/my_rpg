/*
** EPITECH PROJECT, 2021
** my_strvcmp.c
** File description:
** comparaison violente entre 2 str
*/

#include "my.h"

int my_strvcmp (char const *str1 , char const *str2)
{
    int i = 0, j = 0;
    while (str2[j] != '\0')
        j++;
    while (str1[i] == str2[i] && str1[i] != '\0')
        i++;
    if (i == j && i == my_strlen(str1))
        return 0;
    return 1;
}
