/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** pause_utils
*/

#include "my.h"
#include "rpg_header.h"

void manage_mouse_click_level(tags *game)
{
    all_infos()->mouse_click = sfMouse_getPositionRenderWindow(all_infos()->window);
    if (sfFloatRect_contains(&game->f_rects->menu_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        all_sprites()[HUNTER].texture = create_texture("pictures/Characters/Hunter/Hunter.png");
        sfSprite_setTexture(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].texture, sfTrue);
        full_perso(HUNTER, 10 * 50, 10 * 35);
    }
    if (sfFloatRect_contains(&game->f_rects->quit_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        all_sprites()[HUNTER].texture = create_texture("pictures/Characters/Hunter/Hunter_blue.png");
        sfSprite_setTexture(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].texture, sfTrue);
        full_perso(HUNTER, 10 * 50, 10 * 35);
    }
    sfSprite_setScale(all_sprites()[HUNTER].sprite, (sfVector2f) {30, 30});
}
