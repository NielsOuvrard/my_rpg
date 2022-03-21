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

    // hurt
    sfSoundBuffer *hurt_sound_buffer;
    sfSound *hurt_sound;

    // coins
    sfSoundBuffer *coin_sound_buffer;
    sfSound *coin_sound;
    sfClock *coin_clock;

    // Menu
    sfFont *font;
} main_screen;

// create main

main_screen *all_infos (void);

void creat_main (void);

// create time

void full_time (void);

times_clock *all_time (void);

// level 0

void level_0 (sfEvent event);

// level 1

void level_1 (sfEvent event);

// level 2

void level_2 (sfEvent event);

// create sprite

void full_list_sprites (void);

sprite_pictures *all_sprites (void);

// all

int all_levels_game (void);

// open file

char **filepath_to_arr (char *filepath);

// tools 1

main_screen quit_game (main_screen my_main);

int random_int (int min, int max);

int error_args (void);

int help (void);
