/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** create_sounds
*/

#include "my.h"
#include "rpg_header.h"

void create_sounds(void)
{
    all_infos()->sounds = malloc(sizeof(t_sounds));
    t_sounds *sounds = all_infos()->sounds;
    sounds->grass = create_sound("music/grass_walk.ogg");
    sounds->stone = create_sound("music/stone_walk.ogg");
    sounds->wood = create_sound("music/wood_walk.ogg");
    sounds->open_chest = create_sound("music/open_chest.ogg");
}

void play_sound(void)
{
    int curent_x = (all_sprites()[HUNTER].pos.x) / (SIZE_TILE);
    int current_y = (all_sprites()[HUNTER].pos.y) / (SIZE_TILE);
    if (!all_maps()[all_infos()->map_actual].bg[current_y])
        return;
    char bg = all_maps()[all_infos()->map_actual].bg[current_y][curent_x];
    char mg = all_maps()[all_infos()->map_actual].mg[current_y][curent_x];
    stop_all_sounds(bg, mg);
}

void stop_all_sounds(char c, char mg)
{
    if (!is_moving()) {
        stop_sound(all_infos()->sounds->grass);
        stop_sound(all_infos()->sounds->stone);
        stop_sound(all_infos()->sounds->wood);
        return;
    }
    if (c == '7' && is_moving()) {
        stop_sound(all_infos()->sounds->stone);
        stop_sound(all_infos()->sounds->wood);
        check_status(all_infos()->sounds->grass);
    }
    if (c == 'U' || c == 'L' || c == 'G' && is_moving()) {
        stop_sound(all_infos()->sounds->wood);
        check_status(all_infos()->sounds->stone);
        stop_sound(all_infos()->sounds->grass);
    }
    if (c == 'F' || mg == 'l' || mg == 'm' || mg == 'n' && is_moving()) {
        check_status(all_infos()->sounds->wood);
        stop_sound(all_infos()->sounds->grass);
        stop_sound(all_infos()->sounds->stone);
    }
}

void stop_sound(sfSound *sound)
{
    sfSoundStatus status = sfSound_getStatus(sound);
    if (status != sfStopped) {
        sfSound_stop(sound);
        return;
    }
}

void check_status(sfSound *sound)
{
    sfSoundStatus status = sfSound_getStatus(sound);
    if (status != sfStopped) {
        sfSound_setLoop(sound, sfTrue);
    } else
        sfSound_play(sound);
    return;
}