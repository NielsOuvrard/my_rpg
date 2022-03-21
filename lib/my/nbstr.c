/*
** EPITECH PROJECT, 2021
** nbstr.c
** File description:
** lengh of string
*/
#include <stdlib.h>
#include "my.h"

char *nbtstr (int tmp)
{
    int isize = nbsize(tmp);
    char *result = malloc(sizeof(char) * (isize + 2));
    int j = 0;
    if (tmp == 0) {
        result[0] = '0';
        j++;
    }
    if (tmp < 0) {
        result[0] = '-';
        tmp = -tmp;
    }
    while (tmp != 0) {
        result[j] = tmp % 10 + '0';
        tmp = tmp - tmp % 10;
        tmp = tmp / 10;
        j++;
    }
    result[j] = '\0';
    result = my_revstr(result);
    return result;
}
