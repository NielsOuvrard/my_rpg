/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** bonus
*/

#include "my.h"
#include "rpg_header.h"

void event_level_bonus(void)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtKeyPressed &&
        event.key.code == all_keys()->k_interact) {
            all_infos()->text_char = 0;
            sfText_setString(all_texts()->code, "");
            all_infos()->level = GAME;
        }
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (event.type == sfEvtTextEntered) {
            sfText_setPosition(all_texts()->code, (sfVector2f) {815, 500});
            if (event.text.unicode == 8 && all_texts()->pos_text > 0) {
                all_texts()->pos_text--;
                all_texts()->text[all_texts()->pos_text] = '\0';
                sfText_setString(all_texts()->code, all_texts()->text);
            } else {
                all_texts()->text[all_texts()->pos_text] = event.text.unicode;
                all_texts()->text[all_texts()->pos_text + 1] = '\0';
                sfText_setString(all_texts()->code, all_texts()->text);
                all_texts()->pos_text++;
            }
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter) {
            if (my_strcmp(all_texts()->text, "niels grade B") == 0)
                my_putstr("CORRECT\n");
        }
    }
    return;
}

void level_bonus(void)
{
    event_level_bonus();
        disp_map(all_maps()[all_infos()->map_actual].bg);
    print_all_particules();
    disp_mg();
    disp_map(all_maps()[all_infos()->map_actual].fg);
    disp_all_npcs();
    disp_interaction_button();
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    display_hud();
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[WRITE_BOX].sprite, NULL);
    sfRenderWindow_drawText(all_infos()->window, all_texts()->code, NULL);
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}
