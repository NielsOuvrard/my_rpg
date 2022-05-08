/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-mydefender-gabriel.de-souza-morais
** File description:
** welcome_utils
*/

#include "my.h"
#include "rpg_header.h"

void manage_click_welcome_util(tags *game)
{
    if (sfFloatRect_contains(&game->f_rects->quit_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        game->text->tquit = create_texture("pictures/menu_buttons/Quit3.png");
        sfSprite_setTexture(game->sprites->squit, game->text->tquit, sfTrue);
        all_infos()->quit_main = 1;
    }
    if (sfFloatRect_contains(&game->f_rects->scoreboard_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y) &&
    does_save_exists()) {
        game->text->tscoreboard =
        create_texture("pictures/menu_buttons/Scoreboard3.png");
        sfSprite_setTexture(game->sprites->sscoreboard,
        game->text->tscoreboard, sfTrue);
        all_infos()->level = 1;
    }
}

void render_menu(tags *game)
{
    sfRenderWindow_clear(all_infos()->window, sfBlack);
    sfRenderWindow_drawSprite(all_infos()->window, game->sprites->sbackground, NULL);
    sfRenderWindow_drawSprite(all_infos()->window, game->sprites->sstart, NULL);
    sfRenderWindow_drawSprite(all_infos()->window, game->sprites->squit, NULL);
    sfRenderWindow_drawSprite(all_infos()->window, game->sprites->soption, NULL);
    sfRenderWindow_drawSprite(all_infos()->window, game->sprites->sscoreboard, NULL);
    sfRenderWindow_drawSprite(all_infos()->window, game->sprites->seditor, NULL);
    sfRenderWindow_drawText(all_infos()->window, all_texts()->simple_text, NULL);
}

void initialize_bounds_menu(tags *game)
{
    game->f_rects->quit_button_b =
    sfSprite_getGlobalBounds(game->sprites->squit);
    game->f_rects->quit_button_b.width = 420;
    game->f_rects->start_button_b =
    sfSprite_getGlobalBounds(game->sprites->sstart);
    game->f_rects->start_button_b.width = 420;
    game->f_rects->option_button_b =
    sfSprite_getGlobalBounds(game->sprites->soption);
    game->f_rects->option_button_b.width = 420;
    game->f_rects->scoreboard_button_b =
    sfSprite_getGlobalBounds(game->sprites->sscoreboard);
    game->f_rects->scoreboard_button_b.width = 420;
    game->f_rects->editor_button_b =
    sfSprite_getGlobalBounds(game->sprites->seditor);
    game->f_rects->editor_button_b.width = 420;
}

void set_sprite(tags *game)
{
    sfSprite_setTexture(game->sprites->sbackground,
    game->text->tbackground, sfTrue);
    sfSprite_setTexture(game->sprites->sstart, game->text->tstart, sfTrue);
    sfSprite_setScale(game->sprites->sstart, (sfVector2f) {1, 1});
    sfSprite_setPosition(game->sprites->sstart, (sfVector2f) {780, 280});
    sfSprite_setTexture(game->sprites->sscoreboard,
    game->text->tscoreboard, sfTrue);
    sfSprite_setScale(game->sprites->sscoreboard, (sfVector2f) {1, 1});
    sfSprite_setPosition(game->sprites->sscoreboard, (sfVector2f) {780, 440});
    sfSprite_setTexture(game->sprites->squit, game->text->tquit, sfTrue);
    sfSprite_setScale(game->sprites->squit, (sfVector2f) {1, 1});
    sfSprite_setPosition(game->sprites->squit, (sfVector2f) {780, 920});
    sfSprite_setScale(game->sprites->soption, (sfVector2f) {1, 1});
    sfSprite_setScale(game->sprites->sbackground, (sfVector2f) {2.3, 2.1});
    sfSprite_setPosition(game->sprites->soption, (sfVector2f) {780, 760});
    sfSprite_setTexture(game->sprites->soption, game->text->teditor, sfTrue);
    sfSprite_setScale(game->sprites->seditor, (sfVector2f) {1, 1});
    sfSprite_setPosition(game->sprites->seditor, (sfVector2f) {780, 600});
    sfSprite_setTexture(game->sprites->seditor, game->text->teditor, sfTrue);
}
