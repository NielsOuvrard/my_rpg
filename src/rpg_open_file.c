/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** pour open file
*/

#include "my.h"
#include "rpg_header.h"

char *filepath_to_str(char *filepath)
{
    int buff_size = 32000, offset = 0, len = 0;
    char *buff = malloc(sizeof(char) * buff_size);
    int fp = open(filepath, O_RDONLY);
    if (!fp)
        return NULL;
    while ((len = read(fp, buff + offset, buff_size - offset)) > 0)
        offset += len;
    close(fp);
    if (len < 0)
        return NULL;
    buff[offset] = '\0';
    return buff;
}

char **filepath_to_arr(char *filepath)
{
    char *buff = filepath_to_str(filepath);
    if (!buff)
        return NULL;
    int offset, a = 0, k, i, j = 0;
    offset = my_strlen(buff);
    for (int kfc = 0; buff[kfc] != '\0'; kfc++)
        if (buff[kfc] == '\n')
            a++;
    char **map = malloc(sizeof(char *) * (a + 2));
    for (i = 0; a > i; i++) {
        map[i] = malloc(sizeof(char) * (offset));
        for (k = 0; buff[j] != '\n'; k++)
            map[i][k] = buff[j++];
        j++;
        map[i][k] = '\0';
    }
    map[a] = NULL;
    free(buff);
    return map;
}
