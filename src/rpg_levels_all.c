/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

main_screen anim_dog_idle (main_screen my_main)
{
    sfTime dog_time =  sfClock_getElapsedTime(my_main.dog_clock);
    float rect_dog = dog_time.microseconds / 2500000.0;
    if (rect_dog > 0.09) {
        if (my_main.rect.left < 192 - 48) {
            my_main.rect.left += 48;
        } else {
            my_main.rect.left = 0;
        }
        sfSprite_setTextureRect(my_main.sprite_dog, my_main.rect);
        sfClock_restart(my_main.dog_clock);
    }
    return my_main;
}

// all_time()[0].ok  vaut true toutes les 1 secondes
// all_time()[1].ok  vaut true toutes les 1/10 secondes
// all_time()[2].ok  vaut true toutes les 1/100 secondes
// ...

void in_time (void)
{
    int seconds = 1000000;
    for (int i = 0; i < 4; i++) {
        sfTime time_anim = sfClock_getElapsedTime(all_time()[i].clock);
        float rect_anim = time_anim.microseconds;
        if (rect_anim > seconds && !all_time()[i].ok) {
            all_time()[i].ok = true;
            sfClock_restart(all_time()[i].clock);
        } else {
            all_time()[i].ok = false;
        }
        seconds /= 10;
    }
}

void while_it_is_open (void)
{
    sfEvent event;
    // sfMusic_play(my_main.music);
    sfRenderWindow_setFramerateLimit(my_main.window, 60);
    while (sfRenderWindow_isOpen(my_main.window)) {
        in_time();
        sfRenderWindow_drawSprite(my_main.window, all_sprites()[0].sprite, NULL);
        if (my_main.level == 0)
            my_main = level_0(my_main, event);
        if (my_main.level == 1)
            my_main = level_1(my_main, event);
        if (my_main.quit_main) {
            my_main = destroy_main(my_main);
            return;
        }
        sfRenderWindow_display(my_main.window);
    }
}

int all_levels_game (void)
{
    full_list_sprites();
    full_time();
    creat_main();
    // srand(time(NULL));
    while_it_is_open();
    return 0;
}
