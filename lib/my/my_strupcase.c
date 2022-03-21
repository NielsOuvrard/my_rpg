/*
** EPITECH PROJECT, 2021
** my_strupcase.c
** File description:
** upper_case
*/

char *my_strupcase(char *str)
{
    int november = 0;
    while (str[november] != '\0') {
        if (str[november] >= 97 && str[november] <= 122)
            str[november] = str[november] - 32;
        november++;
    }
    return str;
}
