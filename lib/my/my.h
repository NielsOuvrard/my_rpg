/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** fichier include de qualité
*/
#pragma once
#define CTOI(x) ((x) - '0')
#define ITOC(x) ((x) + '0')
#define PAIR(x) ((x % 2 == 0) ? 1 : 0)
#define ABS(x) ((x > 0) ? (x) : -(x))
#define ABS_ZERO(x) ((x > 0) ? (x) : 0)
#define EXIT_ERROR 84
#define EXIT_SUCCESS 0
#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG  "error"

typedef struct formats_str {
    int b_plus;
    int b_diez;
    int b_zero;
    int b_number;
    int b_minus;
    int b_space;
    int b_point;
    int error;
} formats_str;

void free_my_arr (char **arr);

int my_arraylen (char ** world);

int my_compute_power_rec (int nb , int p);

int my_getnbr (char * string);

char *my_int_to_base (int nbr, int base);

char *my_int_to_str(int nb);

int my_intlen (int nbr);

int my_isalpha (char c);

int my_isalphanum (char c);

int my_isdidgit(char a);

int my_isnbr (char *a);

char *my_long_to_base (long nbr, int base);

int my_longlen (long nbr);

char *my_lowercase (char *str);

char *my_memset(char *str, int len, char value);

int my_printf (char * str, ...);

int my_put_str_oct (char *str);

void my_putchar(char c);

void my_putfloat (float nombre_decimal);

void my_putint (int nmb);

void my_putlong (long nmb);

void my_putstr (char const *str);

void my_putunsint (unsigned int nmb);

char *my_revstr (char *str);

int my_show_word_array (char * const *tab);

char **str_to_array (char *str);

char *my_strcat(char *dest , char const *src);

int my_strcmp(char const *s1 , char const *s2);

int my_strncmp(char const *s1 , char const *s2, int idx);

int my_strvcmp (char const *str1 , char const *str2);

char *my_strcpy (char *dest, char const *src);

char *my_strdup (char const *src);

int my_strlen(char const *str);

char *my_strupcase(char *str);

int my_unsintlen (unsigned int nbr);

int nbsize(int tmp);

char *nbtstr (int tmp);
