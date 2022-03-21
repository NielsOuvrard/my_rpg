/*
** EPITECH PROJECT, 2021
** get number.c
** File description:
** get number
*/

void my_putstr(char *str);

char *minus_and_plus (char *string, int *a, int *neg)
{
    while (string[*a] == '-' || string[*a] == '+') {
        while (string[*a] == '-') {
            *neg += 1;
            string++;
        }
        while (string[*a] == '+')
            string++;
    }
    return string;
}

int my_getnbr (char * string)
{
    int negative = 0;
    int a = 0;
    int b = 0;
    int result = 0;
    if ((string[a] < 48 || string[a] > 57) && string[a] != '-')
        return 0;
    string = minus_and_plus(string, &a, &negative);
    while (string[a] >= 48 && string[a] <= 57)
        a++;
    while (b < a) {
        result *= 10;
        result += string[b] - 48;
        b++;
    }
    if (negative % 2 != 0)
        result = - result;
    return result;
}
