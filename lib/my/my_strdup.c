/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** ceci est une description
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy (char *dest, char const *src);

char *my_strdup (char const *src)
{
    int lengh_src = my_strlen(src) + 1;
    char *str = malloc(sizeof(char) * lengh_src);
    str[lengh_src] = '\0';
    my_strcpy(str, src);
    return str;
}
