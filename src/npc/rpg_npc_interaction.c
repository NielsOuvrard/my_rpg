/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rpg_npc_interaction
*/

#include "my.h"
#include "rpg_header.h"

void show_quest(void)
{
    npcs *expl = all_maps()[all_infos()->map_actual].all_npcs;
    while (expl) {
        if (expl->value == 10 && expl->interaction == 1)
            exit (99);
        if (expl->value == 12 && expl->interaction == 1)
            exit (1);
        expl = expl->next;
    }
}

void disp_interaction_button(void)
{
    npcs *expl = all_maps()[all_infos()->map_actual].all_npcs;
    while (expl) {
        sfFloatRect rect_playes = sfSprite_getGlobalBounds(all_sprites()[HUNTER].sprite);
        sfFloatRect rect_npc = sfSprite_getGlobalBounds(all_sprites()[expl->value].sprite);
        rect_npc.height = 60;
        rect_npc.width = 60;
        if (sfFloatRect_intersects(&rect_playes, &rect_npc, NULL)) {
            expl->interaction = 1;
            sfSprite_setScale(all_sprites()[INTERACTION_BT].sprite, (sfVector2f) {2, 2});
            sfSprite_setPosition(all_sprites()[INTERACTION_BT].sprite,
            (sfVector2f) {expl->pos.x - 13, expl->pos.y - 85});
            sfRenderWindow_drawSprite(all_infos()->window,
            all_sprites()[INTERACTION_BT].sprite, NULL);
        }
        expl = expl->next;
    }
}
