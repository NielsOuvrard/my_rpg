/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** level_selection
*/

#include "my.h"
#include "rpg_header.h"

void render_level(tags *game)
{
    sfRenderWindow_clear(all_infos()->window, sfBlack);
    sfRenderWindow_drawSprite(all_infos()->window, game->sprites->sbackground, NULL);
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[HUNTER].sprite, NULL);
    sfRenderWindow_drawSprite(all_infos()->window, game->sprites->squit, NULL);
    sfRenderWindow_drawSprite(all_infos()->window, game->sprites->sstart, NULL);
    sfRenderWindow_drawText(all_infos()->window, all_texts()->simple_text, NULL);
}

void level_event(tags *game)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter) {
            all_infos()->level = 1;
            full_perso(HUNTER, 10 * 50, 10 * 35);
        }
        if (event.type == sfEvtMouseButtonReleased)
            manage_mouse_click_level(game);
    }
}

void set_sprite_level(tags *game)
{
    sfSprite_setTexture(game->sprites->sstart, game->text->tstart, sfTrue);
    sfSprite_setScale(game->sprites->sstart, (sfVector2f) {1, 1});
    sfSprite_setPosition(game->sprites->sstart, (sfVector2f) {750, 700});
    sfSprite_setTexture(game->sprites->squit, game->text->tquit, sfTrue);
    sfSprite_setScale(game->sprites->squit, (sfVector2f) {1, 1});
    sfSprite_setPosition(game->sprites->squit, (sfVector2f) {990, 700});
    sfText_setPosition(all_texts()->simple_text, (sfVector2f) {200, 100});
    game->f_rects->menu_button_b = sfSprite_getGlobalBounds
    (game->sprites->sstart);
    game->f_rects->quit_button_b = sfSprite_getGlobalBounds
    (game->sprites->squit);
}

void initialize_sprite_level(tags *game)
{
    game->text->tstart = create_texture("pictures/menu_buttons/left.png");
    game->sprites->sstart = sfSprite_create();
    game->text->tquit = create_texture("pictures/menu_buttons/right.png");
    game->sprites->squit = sfSprite_create();
    sfText_setString(all_texts()->simple_text,
    "Select your player and press enter to start the game!");
    set_sprite_level(game);
}

void level_selection(tags *game)
{
    initialize_sprite_level(game);
    level_event(game);
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    sfSprite_setPosition(all_sprites()->sprite, (sfVector2f) {950, 750});
    render_level(game);
}
