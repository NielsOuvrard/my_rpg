/*
** EPITECH PROJECT, 2021
** longlen
** File description:
** main quali
*/

int my_longlen (long nbr)
{
    int a = 0;
    while (nbr > 0) {
        nbr /= 10;
        a++;
    }
    return a;
}
