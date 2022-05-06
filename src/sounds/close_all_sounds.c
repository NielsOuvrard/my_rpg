/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** close_all_sounds
*/

#include "my.h"
#include "rpg_header.h"

void close_sounds(void)
{
    t_sounds *sounds = all_infos()->sounds;
    close_soundbuffer(sounds->grass);
    close_soundbuffer(sounds->wood);
    close_soundbuffer(sounds->open_chest);
    close_soundbuffer(sounds->stone);
    sfSound_destroy(sounds->grass);
    sfSound_destroy(sounds->wood);
    sfSound_destroy(sounds->open_chest);
    sfSound_destroy(sounds->stone);
}

void close_soundbuffer(const sfSound *sound)
{
    const sfSoundBuffer *buffer = sfSound_getBuffer(sound);
    sfSoundBuffer *buffer2 = (void *)buffer;
    sfSoundBuffer_destroy(buffer2);
}
