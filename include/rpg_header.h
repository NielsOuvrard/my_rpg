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

#define GRASS 5
#define GHOST 2
#define MAP_EDITOR 2

#define SPRITE_SHEET 1

#define GRASS 5
#define SAND 4
#define WATHER 6
#define DIRT 7

#define SCREEN_MAX_Y 1080
#define SCREEN_MAX_X 1920

typedef struct sprite_pictures {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
    sfVector2i origin;
    sfIntRect rect;
    bool anim;
} sprite_pictures;

typedef struct main_screen {
    // score
    int score;

    // window
    sfRenderWindow* window;
    int level;
    int quit_main;
    sfClock *clock;
    int clock_val;
    bool clock_bool;

    // edito
    sfVector2u size_edit;
    bool is_writing;
    char **map_editor;
    char value_to_print;

    char **map;
    sfVector2f pos_player;
    char move;
    float zoom;
    sfVector2f view_position;
    sfVector2u size_window;

    //view
    sfView *view;

    // sound
    sfMusic *music;
    sfSoundBuffer *hurt_sound_buffer;
    sfSound *hurt_sound;

    // text
    sfText *editor_text;
    sfFont *font;
} main_screen;

// create main

char **editor_create_map (int x, int y);

main_screen *all_infos (void);

void creat_main (void);

// level 0

void level_0 (sfEvent event);

// disp map

void disp_map(char **map);

// level 1

void change_look_ghost(void);

void level_1_clock(sfEvent event);

void modify_var_move(sfEvent event);

void move_pos_player(void);

void level_1 (sfEvent event);

// level 2

void level_2 (sfEvent event);

// map editor

int round_sup (float a);

void change_tile_to_print(sfEvent event);

void change_map_size(sfEvent event);

void le_bon_click_editor (sfEvent event);

void la_bonne_touche_editor (sfEvent event);

void level_map_editor_clock(sfEvent event);

void level_map_editor (sfEvent event);

// create sprite

void full_list_sprites (void);

sprite_pictures *all_sprites (void);

// all

int all_levels_game (void);

// open file

char **filepath_to_arr (char *filepath);

// tools 1

int random_int (int min, int max);
