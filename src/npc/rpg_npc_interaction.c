/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rpg_npc_interaction
*/

#include "my.h"
#include "rpg_header.h"

void event_level_quest(void)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtKeyPressed &&
        event.key.code == all_keyes()->k_interact)
            all_infos()->level = GAME;
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
    }
    return;
}

void npc_quest(void)
{
    npcs *expl = all_maps()[all_infos()->map_actual].all_npcs;
    while (expl) {
        if (expl->value == 10 && expl->interaction == 1)
            ;
        if (expl->value == 12 && expl->interaction == 1)
            ;
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
        expl->interaction = 0;
        if (sfFloatRect_intersects(&rect_playes, &rect_npc, NULL)) {
            expl->interaction = 1;
            sfSprite_setScale(all_sprites()[INTERACTION_BT].sprite, (sfVector2f) {2, 2});
            sfSprite_setPosition(all_sprites()[INTERACTION_BT].sprite,
            (sfVector2f) {expl->pos.x - 13, expl->pos.y - 85});
            sfRenderWindow_drawSprite(all_infos()->window,
            all_sprites()[INTERACTION_BT].sprite, NULL);
            return;
        }
        expl = expl->next;
    }
}

void level_quest(void)
{
    event_level_quest();
    npc_quest();
    // sfSprite_setPosition(all_sprites()[BALLON].sprite, (sfVector2f) {400, 400});
    // sfRenderWindow_drawSprite(all_infos()->window,
    // all_sprites()[BALLON].sprite, NULL);
    if (all_infos()->quit_main == 1)
        return;
    disp_map(all_maps()[all_infos()->map_actual].bg);
    print_all_particules();
    disp_mg();
    disp_map(all_maps()[all_infos()->map_actual].fg);
    disp_all_npcs();
    disp_interaction_button();
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    disp_hud();
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    return;
}
