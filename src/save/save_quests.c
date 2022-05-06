/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** save_quests
*/

#include "my.h"
#include "rpg_header.h"

void save_quests(FILE *fd)
{
    if (all_infos()->quest_done[0] == '\0')
        return;
    fwrite("#quest\n", 1, my_strlen("#quest\n"), fd);
    for (int i = 0; all_infos()->quest_done[i]; i++)
        fwrite(&all_infos()->quest_done[i], 1, 1, fd);
    fwrite("\n", 1, 1, fd);
    return;
}

void save_quests_id(FILE *fd)
{
    if (!all_infos()->quest_id)
        return;
    fwrite("#quest_done\n", 1, my_strlen("#quest_done\n"), fd);
    fwrite(my_itoa(all_infos()->quest_id), 1,
    my_strlen(my_itoa(all_infos()->quest_id)), fd);
    fwrite("\n", 1, 1, fd);
    return;
}

void restore_quests(char *buffer, int *type)
{
    if (*type != 6)
        return;
    int i = 0;
    for (; buffer[i] != '\n'; i++);
    for (int j = 0; j != i; j++) {
        all_infos()->quest_done[j] = buffer[j];
    }
}

void restore_quests_done(char *buffer, int *type)
{
    if (*type != 7)
        return;
    int quest = my_getnbr(buffer);
    all_infos()->quest_id = quest;
    all_infos()->doing_quest = 1;
    return;
}
