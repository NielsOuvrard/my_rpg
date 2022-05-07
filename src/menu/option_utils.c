/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-mydefender-gabriel.de-souza-morais
** File description:
** option_utils
*/

#include "my.h"
#include "rpg_header.h"

void mouse_position_option(tags *game)
{
    all_infos()->mouse_position = sfMouse_getPositionRenderWindow(all_infos()->window);
    if (sfFloatRect_contains(&game->f_rects->menu_button_b,
    all_infos()->mouse_position.x, all_infos()->mouse_position.y)) {
        game->text->trestart = create_texture("pictures/menu_buttons/Menu2.png");
        sfSprite_setTexture(game->sprites->srestart,
        game->text->trestart, sfTrue);
    } else {
        game->text->trestart = create_texture("pictures/menu_buttons/Menu.png");
        sfSprite_setTexture(game->sprites->srestart,
        game->text->trestart, sfTrue);
    }
}

void manage_mouse_click_util(tags *game)
{
    if (sfFloatRect_contains(&game->f_rects->frame60_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        game->text->tframe2 = create_texture("pictures/menu_buttons/60_3.png");
        game->text->tframe = create_texture("pictures/menu_buttons/30.png");
        sfSprite_setTexture(game->sprites->sframe, game->text->tframe, sfTrue);
        sfSprite_setTexture(game->sprites->sframe2,
        game->text->tframe2, sfTrue);
        sfRenderWindow_setFramerateLimit(all_infos()->window, 60);
        all_infos()->frame_rate = 60;
    }
    if (sfFloatRect_contains(&game->f_rects->menu_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        game->text->trestart = create_texture("pictures/menu_buttons/Menu3.png");
        sfSprite_setTexture(game->sprites->srestart,
        game->text->trestart, sfTrue);
        all_infos()->level = 0;
    }
    manage_mouse_click_util_2(game);
}

void manage_mouse_click_option(tags *game)
{
    all_infos()->mouse_click = sfMouse_getPositionRenderWindow(all_infos()->window);
    if (sfFloatRect_contains(&game->f_rects->frame30_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        game->text->tframe = create_texture("pictures/menu_buttons/30_3.png");
        game->text->tframe2 = create_texture("pictures/menu_buttons/60.png");
        sfSprite_setTexture(game->sprites->sframe, game->text->tframe, sfTrue);
        sfSprite_setTexture(game->sprites->sframe2,
        game->text->tframe2, sfTrue);
        all_infos()->frame_rate = 30;
        sfRenderWindow_setFramerateLimit(all_infos()->window, 30);
    }
    manage_mouse_click_util(game);
    render_option(game);
}

void analyse_events_option(tags *game)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click_option(game);
    }
}
