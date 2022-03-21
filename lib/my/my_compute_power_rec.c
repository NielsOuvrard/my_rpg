/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** puissance
*/

int my_compute_power_rec (int nb , int p)
{
    long long_value = 0;
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    if (p > 1) {
        long_value = nb * my_compute_power_rec(nb, p - 1);
        if (long_value >= 2147483647)
            return (0);
        nb = long_value;
        return nb;
    } else {
        return nb;
    }
}
