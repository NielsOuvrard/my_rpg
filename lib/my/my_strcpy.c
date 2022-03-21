/*
** EPITECH PROJECT, 2021
** str_cpy.c
** File description:
** copier un string
*/

char *my_strcpy (char *dest, char const *src)
{
    int i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
