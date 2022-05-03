/*
** EPITECH PROJECT, 2021
** header du RPG
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
#include <stdio.h>

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/Network.h>
#include <SFML/GPUPreference.h>
#include <SFML/OpenGL.h>

#define PI 3.14159265359

#define GAME 1
#define MAP_EDITOR 2
#define INVENTORY 3
#define DIALOGUE 4
#define MISSIONS 5
#define BONUS 6

#define BUFF_SIZE 512

#define SIZE_TILE           50
#define NMB_TILES           72
#define SIZE_TILE_SHEET_X   96
#define SIZE_TILE_SHEET_Y   192
#define SCALE_TILE_SHEET    3.125

#define VALEURE_APPROXIMATIVE_POUR_PASSER_DERRIER_UNE_TUILE_EN_MG 32

#define MAP_EXT_0   0
#define MAP_GREEN_0 1
#define MAP_GREY_0  2
#define MAP_GREY_1  3
#define MAP_WOOD_0  4

#define TYPE_CHANGE_MAP 0
#define TYPE_CHEST      1

#define HUNTER          0
#define SPRITE_SHEET    1
#define NINJA           2
#define BANANA          3
#define DEMON           4
#define CHECK_BOX       5
#define EMPTY_BOX       6
#define CROSS_BOX       7
#define SELEC_BOX       8
#define LIFE            9
#define NPC            10
#define INTERACTION_BT 11
#define NPC2           12
#define BALLON         13
#define NPC3           14
#define APPLE          15
#define PARCHMENT      16
#define NPC4           17
#define ARROW          18
#define WRITE_BOX      19
#define INFO           20
#define BANANA_INFO    "The best bananas of our\n village !\n Gives you 2 health points\n and full stamina !\n Press 'L' to eat\n Press 'Q' to drop\n"
#define APPLE_INFO    "The best apples of our\n village !\n Gives you 1 health points\n and half stamina !\n Press 'L' to eat\n Press 'Q' to drop\n"
#define SCREEN_MAX_Y 1080
#define SCREEN_MAX_X 1920

typedef struct sf_text {
    sfText *simple_text;
    sfText *code;
    sfFont *font;
    char *text;
    int pos_text;
} sf_text;

typedef struct sprite_pictures {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f origin;
    sfIntRect rect;
    char anim;
} sprite_pictures;

typedef struct vec2d {
    float x;
    float y;
} vec2d_t;

typedef struct projectile {
    sprite_pictures sprite_picture;
    bool should_render;
    int damage;
    vec2d_t velocity;
} projectile_t;

typedef struct struct_inventory {
    int object;
    struct struct_inventory *next;
} struct_inventory;

typedef struct npcs {
    int value;
    int radius;
    int move_type;
    int x;
    int y;
    int og_x;
    int og_y;
    int interaction;
    char anim;
    bool printed;
    sfClock *clock;
    sfVector2f pos;
    sfIntRect rect;
    struct npcs *next;
} npcs;

typedef struct enemies {
    struct enemies *next;
    sfVector2f pos;
    int health_points;
    int value;
    sfClock *clock;
    int radius;
    int move_type;
    int x;
    int y;
    int og_x;
    int og_y;
    bool printed;
    char anim;
    sfIntRect rect;
} enemies;

typedef struct struct_keys {
    sfKeyCode k_up;
    sfKeyCode k_sprint;
    sfKeyCode k_down;
    sfKeyCode k_left;
    sfKeyCode k_right;
    sfKeyCode k_map;
    sfKeyCode k_interact;
    sfKeyCode k_open_bag;
    sfKeyCode k_open_missions;
    sfKeyCode shoot;
    sfKeyCode zoom_in;
    sfKeyCode zoom_out;
    sfKeyCode k_inv_right;
    sfKeyCode k_inv_left;
    sfKeyCode k_no;
    sfKeyCode k_yes;
} struct_keys;

typedef struct struct_particule {
    int size;
    sfVector2f pos;
    sfColor color;
    struct struct_particule *next;
} struct_particule;

typedef struct struct_interact {
    int x;
    int y;
    int a_x;
    int a_y;
    int type;
    // ? bool locked; ?
    int data;
    struct struct_interact *next;
} struct_interact;

typedef struct struct_maps {
    char **bg;
    char **mg;
    char **fg;
    char **is_printed;
    npcs *all_npcs;
    enemies *all_ennemis;
    struct_interact *interact;
    // infos items ? in chest
    // items / panneaux ?
} struct_maps;

typedef struct editor_screen {
    sfVector2u size_edit;
    bool is_writing;
    char **map_bg;
    char **map_mg;
    char **map_fg;
    char value_to_print;
    char *dir_save;
    sfText *editor_text;
    sfFont *font;
    char edit_ground;
    char **ptr_map_edit;
    bool v_bg;
    bool v_mg;
    bool v_fg;
} editor_screen;

typedef struct main_screen {
    // window
    sfRenderWindow* window;
    int level;
    int quit_main;
    sfClock *clock;
    int clock_val;
    struct_inventory *inventory;
    int map_actual;
    sfVector2f pos_player;
    int life;
    float stamina;
    char move;
    int quest_id;
    int entering_password;
    bool doing_quest;
    char quest_done[3];
    int nb_of_enemies_outside;
    bool move_u;
    bool move_d;
    bool move_r;
    bool move_l;
    bool printed;
    bool sprint;
    bool can_move;
    int nb_of_zoom;
    sfClock *stamina_clock;
    sfClock *text_clock;
    int text_char;
    char last_move;
    float zoom;
    sfVector2f view_position;
    sfVector2u size_window;
    int inventory_move;
    // particules :
    struct_particule *particules;

    //view
    sfView *view;
    sfView *hud_view;

    // sound
    sfMusic *music;
    sfSoundBuffer *click_sound_buffer;
    sfSound *click_sound;
} main_screen;

// * ////////////// CREATE DIR //////////////////////////////////////////

// keyes

void create_keys (void);

struct_keys *all_keys (void);

void qwerty_keyes (void);

// create editor

editor_screen *all_editor(void);

char **editor_create_map(int x, int y, char c);

void initialize_editor_vals(void);

void create_editor(void);

// create main

main_screen *all_infos(void);

void create_main(void);

// create maps

void fill_map_dictionary(void);

struct_maps *all_maps(void);

// create texts

sf_text *all_texts(void);

void create_texts(void);

// create sprite

void fill_sprite_dictionary(void);

sprite_pictures *all_sprites(void);

// * ////////////// LEVEL1 DIR //////////////////////////////////////////
// interact change map

void move_to_map(int map, int x, int y);

int player_is_on_case(int x, int y);

void check_all_intecract_map_actual(void);

// disp mg

void disp_mg(void);

// disp map

void disp_map(char **map);

// level 1 anim enemis

void anim_all_enemies(void);

// level 1 anim hunter

void anim_perso_according_to_int(void);

// level 1 anim

void anim_perso (void);

// change look hunter

// void change_look_hunter(void);

// enevt

void recalculate_the_sprite_perso(void);

void event_level_game(sfEvent event);

// level 1 var move

void idle_perso(void);

void move_to_map(int map, int x, int y);

// void move_to_salle_une (void);

// void move_to_exterieure_une (void);

void modify_var_move_next(sfEvent event, char a);

void modify_var_move(sfEvent event);

// level 1

void level_game_animations(void);

void modify_var_move(sfEvent event);

void move_pos_player(void);

void display_hud(void);

void level_game(sfEvent event);

// write map

void write_maps(void);

// particules

void find_tile_particle(char c, int i, int j);

void add_particules(sfVector2f pos, int size, sfColor color);

void anim_all_particules(void);

void print_all_particules(void);

// * ////////////// EDITOR DIR //////////////////////////////////////////

// change size map tools

void add_new_y(char **map, int size, char c);

void delete_y(char **map, int size);

void add_new_x(char **map, int size, char c);

void delete_x(char **map, int size);

// change size map

void change_size_map(void);

// disp map editor

void disp_map_next(char **map, int i, int j);

void disp_map_editor(char **map);

void disp_value_to_print(void);

// disp right

void display_boxes(void);

void disp_text_size(void);

void disp_text_and_boxes(void);

// le bon click editor

void le_bon_click_editor(sfEvent event);

// map editor click infos right

void editor_click_infos_right(sfVector2i pos_mouse);

// existing file

void edit_existing_file(char *filepath_dir);

// map editor

int round_sup(float a);

void change_tile_to_print(sfEvent event);

void change_map_size(sfEvent event);

void le_bon_click_editor (sfEvent event);

void la_bonne_touche_editor (sfEvent event);

void level_map_editor_clock(void);

void level_map_editor(sfEvent event);

// * ////////////// INVENTORY DIR //////////////////////////////////////////

void level_inventory(sfEvent event);

// * ////////////// SRC DIR //////////////////////////////////////////

// ennemis

void move_all_ennemies(void);

void get_move_val(enemies *enemy);

int can_be_moved(int x, int y, enemies *enemy);

void get_new_vals(enemies *enemy);

// ennemis

void add_enemies_to_list(int map, int value, int x, int y);

void explore_map_find_all_ennemis_next(int map, int i, int j);

void explore_map_find_all_ennemis(int map);

void display_all_enemies(void);

// npcs

void explore_map_find_all_npcs(int map);

void disp_all_npcs(void);

void disp_interaction_button(void);

void level_quest(void);

// missions

void level_missions(void);

// bonus

void level_bonus(void);

// free

void free_map(int i);

void free_particules(void);

// level 2 (pause peut-etre)

void level_2(sfEvent event);

// level 0

void level_0(sfEvent event);

// all

int start_game(int ac, char **av);

// open file

char **filepath_to_arr(char *filepath);

// tools 1

int random_int(int min, int max);

void get_move_val(enemies *enemy);

int can_move(int x, int y);

int is_movable(char my_mg, char my_bg);

void check_stamina(void);

void display_stamina(void);

void increase_stamina(void);

void move_sprint(int x, int y);

void fill_inventory(void);

void print_infos(int run, struct_inventory *obj, int x, int y);

void add_to_inventory (struct_inventory **list, int value);

void scale_inventorybox(void);

void pick_inventorybox(int x, int y, int run);

void change_val_box(int val);

int nmb_inv(void);

char *my_strdup_to (char const *src, int len);

void new_projectile_manager(void);

projectile_t *new_projectile(vec2d_t position, vec2d_t velocity, int damage, int type);

projectile_t **get_projectile_dictionary();

void shoot_projectile(projectile_t *projectile);

void projectile_game_tick(void);

void projectile_render_tick(void);

vec2d_t create_vector(float x, float y);

float get_angle_in_degrees(projectile_t *projectile);

void update_projectile_rotation(projectile_t *projectile);

void print_infos(int run, struct_inventory *obj, int x, int y);

void check_enemies_collision(projectile_t *projectile);

void print_item_infos(struct_inventory *obj, int x, int y);

void write_infos_to_file(void);

void save_position_to_file(FILE *fd);

void save_view_to_file(FILE *fd);

void save_inventory_to_file(FILE *fd);

int does_save_exists(void);

void handle_player_pos(char *buffer, int *type, int run);

sfVector2f handle_view_pos(char *buffer, int *type, int run, sfVector2f pos);

void get_info_save(void);

void save_map_actual(FILE *fd);

void handle_map_actual(int *type, char *buffer);
