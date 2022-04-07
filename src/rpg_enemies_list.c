/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** enemies_list
*/

#include "my.h"
#include "rpg_header.h"

void add_enemies_to_list(enemies **list, int value, int x, int y)
{
    enemies *new_enemy = malloc(sizeof(enemies));
    new_enemy->pos.x = x;
    new_enemy->pos.y = y;
    new_enemy->value = value;
    new_enemy->next = NULL;
    if (*list == NULL) {
        *list = new_enemy;
        return;
    }
    enemies *last = *list;
    while (last->next != NULL)
        last = last->next;
    last->next = new_enemy;
}

void print_enemies(enemies **list)
{
    enemies *temp = *list;
    while (temp != NULL) {
        sfSprite_setPosition(all_sprites()[temp->value].sprite, temp->pos);
        sfRenderWindow_drawSprite(all_infos()->window, all_sprites()
        [temp->value].sprite, NULL);
        temp = temp->next;
    }
}

void create_enemy(enemies **list)
{
    add_enemies_to_list(list, DEMON, 45, 12);
    //todo : generer plusieurs ennemis de différents types
}