/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1 , char const *s2)
{
    int i = 0, j = 0;
    unsigned int value;
    while (s2[j] != '\0')
        j++;
    while (s1[i] == s2[i] && i != j)
        i++;
    if (i == j)
        return 0;
    value = s1[i] - s2[i];
    return (value);
}
