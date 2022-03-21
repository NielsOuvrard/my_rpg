/*
** EPITECH PROJECT, 2021
** header du my snake
** File description:
** bcp de definitions
*/
#pragma once

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/Network.h>
#include <SFML/GPUPreference.h>
#include <SFML/OpenGL.h>

#define SCREEN_MAX_Y 1080
#define SCREEN_MAX_X 1920

typedef struct sprite_pictures {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2i pos;
    sfVector2i origin;
    sfIntRect rect;
} sprite_pictures;

typedef struct times_clock {
    sfClock *clock;
    bool ok;
} times_clock;

typedef struct main_screen {
    // score
    int score;
    sfText *score_txt;

    // window
    sfMusic *music;
    sfRenderWindow* window;
    int level;
    int quit_main;

    // cactus
    sfSprite* sprite_cac;
    sfVector2f sprite_cac_pos;
    sfClock *cac_clock;
    sfVector2f scale_cac;

    // hurt
    sfSoundBuffer *hurt_sound_buffer;
    sfSound *hurt_sound;

    // coins
    sfSoundBuffer *coin_sound_buffer;
    sfSound *coin_sound;
    sfSprite* sprite_coin;
    sfVector2f sprite_coin_pos;
    sfClock *coin_clock;
    sfVector2f scale_coin;

    // dirt
    sfSprite* sprite_dirt;
    sfVector2f sprite_dirt_pos;
    sfClock *dirt_clock;
    sfVector2f scale_dirt;

    // menu
    sfSprite* sprite_menu;
    sfVector2f sprite_menu_pos;

    // menu
    sfSprite* sprite_difficulty;
    sfVector2f sprite_difficulty_pos;

    // dog
    char *idle;
    sfIntRect rect;
    sfSprite* sprite_dog;
    sfVector2f sprite_dog_pos;
    sfClock *dog_clock;
    sfClock *dog_clock_jump;

    // background
    sfTexture* texture_bg;
    sfSprite* bg_sprite;

    // Menu
    sfFont *font;
} main_screen;

// create 2

main_screen creat_dog_init_variables (main_screen my_main);

main_screen creat_dog (main_screen my_main);

main_screen creat_bg (main_screen my_main);

// create 1

main_screen creat_txt_score (main_screen my_main);

main_screen creat_menu (main_screen my_main);

main_screen creat_difficulty (main_screen my_main);

main_screen initialise_variables_music (main_screen my_main);

main_screen creat_main (void);

// level 0

main_screen destroy_main (main_screen my_main);

main_screen event_level_0 (main_screen my_main, sfEvent event);

main_screen level_0 (main_screen my_main, sfEvent event);

// level 1

main_screen event_level_1 (main_screen my_main, sfEvent event);

main_screen level_1 (main_screen my_main, sfEvent event);

// levels all

int all_levels_game (void);

// tools 1

main_screen quit_game (main_screen my_main);

int random_int (int min, int max);

int error_args (void);

int help (void);


// create

sprite_pictures *all_sprites (void);

times_clock *all_time (void);

// open file

char **filepath_to_arr (char *filepath);
