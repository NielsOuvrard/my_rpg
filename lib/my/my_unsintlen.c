/*
** EPITECH PROJECT, 2021
** my_unsintlen
** File description:
** yes
*/

int my_unsintlen (unsigned int nbr)
{
    int a = 0;
    while (nbr > 0) {
        nbr /= 10;
        a++;
    }
    return a;
}
