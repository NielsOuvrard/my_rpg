/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** welcome
*/

#include "my.h"
#include "rpg_header.h"

void mouse_position_util_menu_2(tags *game)
{
    if (sfFloatRect_contains(&game->f_rects->editor_button_b,
    all_infos()->mouse_position.x, all_infos()->mouse_position.y)) {
        game->text->teditor = create_texture("pictures/menu_buttons/map_editor2.png");
        sfSprite_setTexture(game->sprites->seditor, game->text->teditor, sfTrue);
    } else {
        game->text->teditor =
        create_texture("pictures/menu_buttons/map_editor.png");
        sfSprite_setTexture(game->sprites->seditor, game->text->teditor, sfTrue);
    }
}

void manage_mouse_click_menu_utils_2(tags *game)
{
    all_infos()->mouse_click = sfMouse_getPositionRenderWindow(all_infos()->window);
    if (sfFloatRect_contains(&game->f_rects->editor_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        game->text->teditor = create_texture("pictures/menu_buttons/map_editor3.png");
        sfSprite_setTexture(game->sprites->seditor, game->text->teditor, sfTrue);
        sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
        all_infos()->level = 2;
    }
    render_menu(game);
}

void manage_mouse_click_menu(tags *game)
{
    all_infos()->mouse_click = sfMouse_getPositionRenderWindow(all_infos()->window);
    if (sfFloatRect_contains(&game->f_rects->start_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        game->text->tstart = create_texture("pictures/menu_buttons/Play3.png");
        sfSprite_setTexture(game->sprites->sstart, game->text->tstart, sfTrue);
        reset_save();
        all_infos()->level = 11;
    }
    if (sfFloatRect_contains(&game->f_rects->option_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        game->text->toption = create_texture("pictures/menu_buttons/Options3.png");
        sfSprite_setTexture(game->sprites->soption,
        game->text->toption, sfTrue);
        all_infos()->level = 8;
    }
    manage_click_welcome_util(game);
    manage_mouse_click_menu_utils_2(game);
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
    mouse_position_util_menu_2(game);
    sfText_setString(all_texts()->simple_text, "My_RPG");
    sfText_setPosition(all_texts()->simple_text, (sfVector2f) {790, 100});
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    analyse_events_menu(game, event);
    render_menu(game);
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}
