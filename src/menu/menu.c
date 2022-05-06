/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** welcome
*/

#include "my.h"
#include "rpg_header.h"

void manage_mouse_click_menu(tags *game)
{
    all_infos()->mouse_click = sfMouse_getPositionRenderWindow(all_infos()->window);
    if (sfFloatRect_contains(&game->f_rects->start_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        game->text->tstart = create_texture("pictures/menu_buttons/Play3.png");
        sfSprite_setTexture(game->sprites->sstart, game->text->tstart, sfTrue);
        all_infos()->level = 1;
    }
    if (sfFloatRect_contains(&game->f_rects->option_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        game->text->toption = create_texture("pictures/menu_buttons/Options3.png");
        sfSprite_setTexture(game->sprites->soption,
        game->text->toption, sfTrue);
        all_infos()->level = 8;
    }
    manage_click_welcome_util(game);
    render_menu(game);
}

void analyse_events_menu(tags *game, sfEvent event)
{
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click_menu(game);
    }
}

void level_menu(tags *game, sfEvent event)
{
    mouse_position_menu(game);
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    analyse_events_menu(game, event);
    render_menu(game);
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}
