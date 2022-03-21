/*
** EPITECH PROJECT, 2021
** my_isalpha.c
** File description:
** the char is alpha value
*/

int my_isalpha (char c)
{
    if ('A' <= c && 'Z' >= c)
        return 1;
    if ('a' <= c && 'z' >= c)
        return 1;
    return 0;
}
