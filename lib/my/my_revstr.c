/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** reverse a string
*/

int my_strlen(char *str);

char *my_revstr (char *str)
{
    int i = my_strlen(str) - 1;
    int j = 0;
    char c;

    while (j < (i / 2) + 1) {
        c = str[i - j];
        str[i - j] = str[j];
        str[j] = c;
        ++j;
    }
    return (str);
}
