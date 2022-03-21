/*
** EPITECH PROJECT, 2021
** epitech.c
** File description:
** prototypes
*/
#include "my.h"

void my_putchar(char c);

void my_putfloat (float nombre_decimal)
{
    int nombre_entier = nombre_decimal, diviseur = 1;
    if (nombre_decimal < 0) {
        my_putchar('-');
        nombre_entier = -nombre_entier;
    }
    while (nombre_decimal / diviseur > 9.9 || nombre_decimal / diviseur < -9.9)
        diviseur *= 10;
    while (diviseur >= 1) {
        my_putchar('0' + ((nombre_entier / diviseur) % 10));
        diviseur /= 10;
    }
    my_putchar('.');
    nombre_entier = nombre_decimal * 1000000;
    int alpha = 100000;
    for (int a = 0; a < 6; a++) {
        my_putchar('0' + (nombre_entier / alpha) % 10);
        alpha /= 10;
        if (alpha == 0)
            alpha++;
    }
}
