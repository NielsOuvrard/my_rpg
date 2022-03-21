/*
** EPITECH PROJECT, 2021
** my_putint.c
** File description:
** my_putint
*/

void my_putchar(char c);

void my_putunsint (unsigned int nmb)
{
    int result = 0;

    if (nmb < 0) {
        my_putchar('-');
        nmb = -nmb;
    }
    if (10 > nmb) {
        my_putchar(nmb + '0');
    } else if (9 < nmb) {
        my_putunsint(nmb / 10);
        result = nmb % 10;
        my_putchar(result + '0');
    }
}
