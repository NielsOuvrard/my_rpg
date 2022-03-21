/*
** EPITECH PROJECT, 2021
** my_lowercase.c
** File description:
** maj to min
*/
char *my_strdup (char const *src);

char *my_lowercase (char *str)
{
    char *retour = my_strdup(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (retour[i] >= 'A' && retour[i] <= 'Z')
            retour[i] = retour[i] + 32;
    }
    return retour;
}
