/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-mydefender-gabriel.de-souza-morais
** File description:
** welcome_utils2
*/

#include "my.h"
#include "rpg_header.h"

sfTexture *create_texture(char *path)
{
    sfTexture *texture;
    texture = sfTexture_createFromFile(path, NULL);
    return texture;
}

void mouse_position_menu(tags *game)
{
    all_infos()->mouse_position = sfMouse_getPositionRenderWindow(all_infos()->window);
    if (sfFloatRect_contains(&game->f_rects->start_button_b,
    all_infos()->mouse_position.x, all_infos()->mouse_position.y)) {
        game->text->tstart = create_texture("pictures/menu_buttons/Play2.png");
        sfSprite_setTexture(game->sprites->sstart, game->text->tstart, sfTrue);
    } else {
        game->text->tstart = create_texture("pictures/menu_buttons/Play.png");
        sfSprite_setTexture(game->sprites->sstart, game->text->tstart, sfTrue);
    }
    if (sfFloatRect_contains(&game->f_rects->option_button_b,
    all_infos()->mouse_position.x, all_infos()->mouse_position.y)) {
        game->text->toption = create_texture("pictures/menu_buttons/Options2.png");
        sfSprite_setTexture(game->sprites->soption,
        game->text->toption, sfTrue);
    } else {
        game->text->toption = create_texture("pictures/menu_buttons/Options.png");
        sfSprite_setTexture(game->sprites->soption,
        game->text->toption, sfTrue);
    }
    mouse_position_util_menu(game);
}

void mouse_position_util_menu(tags *game)
{
    if (sfFloatRect_contains(&game->f_rects->quit_button_b,
    all_infos()->mouse_position.x, all_infos()->mouse_position.y)) {
        game->text->tquit = create_texture("pictures/menu_buttons/Quit2.png");
        sfSprite_setTexture(game->sprites->squit, game->text->tquit, sfTrue);
    } else {
        game->text->tquit = create_texture("pictures/menu_buttons/Quit.png");
        sfSprite_setTexture(game->sprites->squit, game->text->tquit, sfTrue);
    }
    if (sfFloatRect_contains(&game->f_rects->scoreboard_button_b,
    all_infos()->mouse_position.x, all_infos()->mouse_position.y)) {
        game->text->tscoreboard = create_texture
        ("pictures/menu_buttons/Scoreboard2.png");
        sfSprite_setTexture(game->sprites->sscoreboard,
        game->text->tscoreboard, sfTrue);
    } else {
        game->text->tscoreboard =
        create_texture("pictures/menu_buttons/Scoreboard.png");
        sfSprite_setTexture(game->sprites->sscoreboard,
        game->text->tscoreboard, sfTrue);
    }
}

void initialize_sprite_menu(tags *game)
{
    game->text->toption = create_texture("pictures/menu_buttons/Options.png");
    game->sprites->soption = sfSprite_create();
    game->text->tscoreboard =
    create_texture("pictures/menu_buttons/Scoreboard.png");
    game->sprites->sscoreboard = sfSprite_create();
    game->text->tbackground = create_texture("pictures/Background.jpg");
    game->sprites->sbackground = sfSprite_create();
    game->text->tstart = create_texture("pictures/menu_buttons/Play.png");
    game->sprites->sstart = sfSprite_create();
    game->text->tquit = create_texture("pictures/menu_buttons/Quit.png");
    game->sprites->squit = sfSprite_create();
    game->text->teditor = create_texture("pictures/menu_buttons/Play.png");
    game->sprites->seditor = sfSprite_create();
    set_sprite(game);
}
