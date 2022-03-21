/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** my_strcmp
*/

int my_strncmp (char const *s1 , char const *s2, int idx)
{
    int i = 0, j = 0;
    unsigned int value;
    while (s2[j] != '\0' && j < idx)
        j++;
    while (s1[i] == s2[i] && i != j && i < idx)
        i++;
    if (i == j && i == idx)
        return 0;
    value = s1[i] - s2[i];
    return value;
}

// int my_strncmp (char const *s1 , char const *s2, int idx)
// {
//     int i = 0, j = 0;
//     unsigned int value;
//     while (s2[j] != '\0')
//         j++;
//     while (s1[i] == s2[i] && s1[i] != '\0')
//         i++;
//     if (i == j && i == idx)
//         return 0;
//     value = s1[i] - s2[i];
//     return value;
// }
