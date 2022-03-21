/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

// main_screen creat_txt_score (main_screen my_main)
// {
//     my_main.font = sfFont_createFromFile("font/coolvetica_rg.ttf");
//     my_main.score_txt = sfText_create();
//     sfText_setFont(my_main.score_txt, my_main.font);
//     sfText_setString(my_main.score_txt, "score : 0");
//     sfText_setColor(my_main.score_txt, sfBlack);
//     sfText_setCharacterSize(my_main.score_txt, 30);
//     sfVector2f pos_txt = {50, 50};
//     sfText_setPosition(my_main.score_txt, pos_txt);
//     return my_main;
// }

// main_screen creat_menu (main_screen my_main)
// {
//     sfTexture* tex_menu = sfTexture_createFromFile("pictures/menu.png", NULL);
//     my_main.sprite_menu = sfSprite_create();
//     my_main.sprite_menu_pos.x = SCREEN_MAX_X / 2 - (1606 * 0.3 / 2);
//     // 1606x2250
//     my_main.sprite_menu_pos.y = SCREEN_MAX_Y / 10; //my_main.ground_y - 240;
//     sfSprite_setPosition(my_main.sprite_menu, my_main.sprite_menu_pos);
//     sfVector2f scale_menu = {0.3, 0.3};
//     sfSprite_setScale(my_main.sprite_menu, scale_menu);
//     sfSprite_setTexture(my_main.sprite_menu, tex_menu, sfTrue);
//     // sfSprite_setTextureRect(my_main.sprite_menu, my_main.rect);
//     return my_main;
// }

// main_screen initialise_variables_music (main_screen my_main)
// {
//     my_main.level = 0;
//     my_main.quit_main = 0;
//     my_main.score = 0;
//     my_main.music = sfMusic_createFromFile("music/music.ogg");
//     sfMusic_setVolume(my_main.music, 50);
//     my_main.coin_sound_buffer = sfSoundBuffer_createFromFile("music/minecraft_click.ogg");
//     my_main.hurt_sound_buffer = sfSoundBuffer_createFromFile("music/hurt.ogg");
//     my_main.coin_sound = sfSound_create();
//     sfSound_setBuffer(my_main.coin_sound, my_main.coin_sound_buffer);
//     // sfSound_play(my_main.coin_sound);
//     return my_main;
// }
static sprite_pictures *value;

void full_list_sprites (void)
{
    char **arr = filepath_to_arr("pictures/pictures.txt");
    int nbr = my_arraylen(arr), i;
    value = malloc(sizeof(sprite_pictures) * (nbr + 1));
    for (i = 0; arr[i]; i++) {
        value[i].sprite = sfSprite_create();
        value[i].texture = sfTexture_createFromFile(arr[i], NULL);
        sfSprite_setTexture(value[i].sprite, value[i].texture, sfTrue);
        value[i].rect.height = 0;
        value[i].rect.top = 0;
        value[i].rect.left = 0;
        value[i].rect.width = 0;
        value[i].scale.x = 1;
        value[i].scale.y = 1;
        value[i].origin.x = 0;
        value[i].origin.y = 0;
        value[i].pos.x = 0;
        value[i].pos.x = 0;
    }
}

sprite_pictures *all_sprites (void)
{
    return value;
}

main_screen creat_main (void)
{
    main_screen my_main;
    sfVideoMode mode = {SCREEN_MAX_X, SCREEN_MAX_Y, 60};
    my_main.window = sfRenderWindow_create(mode, "RPG", sfResize | sfClose, NULL);
    my_main.level = 0;
    my_main.quit_main = 0;
    full_list_sprites();
    my_printf("%d\n", 4);
    my_printf("%d\n", all_sprites()[1].origin);
    return my_main;
}
