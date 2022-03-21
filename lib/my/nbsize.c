/*
** EPITECH PROJECT, 2021
** nbsize.c
** File description:
** lengh of string
*/

int nbsize(int tmp)
{
    int isize = 0;
    while (tmp != 0){
        tmp = tmp / 10;
        isize++;
    }
    return isize;
}
