/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** description
*/

char *my_strcat(char *dest, char const *src)
{
    int alpha = 0;
    int omega = 0;
    while (dest[alpha] != '\0')
        alpha++;
    while (src[omega] != '\0') {
        dest[alpha + omega] = src[omega];
        omega++;
    }
    dest[alpha + omega] = '\0';
    return (dest);
}
