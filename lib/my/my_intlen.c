/*
** EPITECH PROJECT, 2021
** my_intlen.c
** File description:
** my_intlen
*/

int my_intlen (int nbr)
{
    int a = 0;
    while (nbr > 0) {
        nbr /= 10;
        a++;
    }
    return a;
}
