/*
** EPITECH PROJECT, 2022
** free_my_arr
** File description:
** free
*/

#include <stdlib.h>

void free_my_arr (char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}
