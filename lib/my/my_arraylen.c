/*
** EPITECH PROJECT, 2021
** my_arraylen.c
** File description:
** lengh of string
*/

#include <stdlib.h>

int my_arraylen (char ** world)
{
    int a = 0;
    while (world[a] != NULL)
        a++;
    return (a);
}
