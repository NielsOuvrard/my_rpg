/*
** EPITECH PROJECT, 2021
** my_memset;c
** File description:
** set in memory of str
*/

char *my_memset (char *str, int len, char value)
{
    for (int i = 0; i < len; i++)
        str[i] = value;
    return (str);
}
