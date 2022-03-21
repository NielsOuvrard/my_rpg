/*
** EPITECH PROJECT, 2021
** my_isnbr
** File description:
** my_isnbr
*/

int my_isnbr (char *a)
{
    int the_return = 1;
    for (int k = 0; a[k] != '\0'; k++) {
        if (a[k] == '-' && k == 0)
            k++;
        if (a[k] < '0' || '9' < a[k])
            the_return = 0;
    }
    return the_return;
}
