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

#define MAP_EDITOR 2

#define HUNTER 0
#define SPRITE_SHEET 1
#define NINJA 2
#define BANANA 3
#define DEMON 4
#define CHECK_BOX 5
#define EMPTY_BOX 6
#define CROSS_BOX 7

#define SCREEN_MAX_Y 1080
#define SCREEN_MAX_X 1920

typedef struct sprite_pictures {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f origin;
    sfIntRect rect;
    char anim;
} sprite_pictures;

typedef struct struct_maps {
    char **bg;
    char **mg;
    char **fg;
    // linked list ennemis ?
    // infos items ? in chest
    // lieu de spawn
    // interaction portes / items
} struct_maps;

typedef struct editor_screen {
    // edito
    sfVector2u size_edit;
    bool is_writing;
    char **map_bg;
    char **map_mg;
    char **map_fg;
    char value_to_print;
    // text
    sfText *editor_text;
    sfFont *font;
    char edit_ground;
    bool v_bg;
    bool v_mg;
    bool v_fg;
} editor_screen;

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


    int map_actual;
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

} main_screen;

// * ////////////// CREATE DIR //////////////////////////////////////////

// create editor

editor_screen *all_editor (void);

char **editor_create_map (int x, int y);

void initialize_editor_vals(void);

void creat_editor (void);

// create main

char **editor_create_map (int x, int y);

main_screen *all_infos (void);

void creat_main (void);

// create maps

void full_list_maps(void);

struct_maps *all_maps(void);

// create sprite

void full_list_sprites (void);

sprite_pictures *all_sprites (void);

// * ////////////// LEVEL1 DIR //////////////////////////////////////////

// disp map

void disp_map(char **map);

// level 1 anim hunter

void anim_perso_according_to_int (int sprite);

// level 1 anim

void anim_perso (void);

void change_look_ghost(void);

// level 1

void move_to_salle_une (void);

void move_to_exterieure_une (void);

void change_look_ghost(void);

void level_1_clock(sfEvent event);

void modify_var_move(sfEvent event);

void move_pos_player(void);

void level_1 (sfEvent event);

// * ////////////// EDITOR DIR //////////////////////////////////////////

// disp map editor

void disp_map_editor(void);

void disp_value_to_print(void);

// disp right

void disp_boxes (void);

void disp_text_size (void);

void disp_text_and_boxes (void);

// map editor click infos right

void editor_click_infos_right (sfVector2i pos_mouse);

// map editor

int round_sup (float a);

void change_tile_to_print(sfEvent event);

void change_map_size(sfEvent event);

void le_bon_click_editor (sfEvent event);

void la_bonne_touche_editor (sfEvent event);

void level_map_editor_clock(sfEvent event);

void level_map_editor (sfEvent event);

// * ////////////// SRC DIR //////////////////////////////////////////

// level 2 (pause peut-etre)

void level_2 (sfEvent event);

// level 0

void level_0 (sfEvent event);

// all

int all_levels_game (void);

// open file

char **filepath_to_arr (char *filepath);

// tools 1

int random_int (int min, int max);
