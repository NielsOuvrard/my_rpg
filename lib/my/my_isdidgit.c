/*
** EPITECH PROJECT, 2021
** my_isnbr
** File description:
** my_isnbr
*/

int my_isdidgit(char a)
{
    if (a >= '0' && '9' >= a)
        return 1;
    return 0;
}
