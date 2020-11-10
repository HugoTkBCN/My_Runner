/*
** EPITECH PROJECT, 2019
** create destroy sound
** File description:
** runner
*/

#include "../../include/my.h"

void create_death_win_sound(all_game_t *all_game)
{
    all_game->death.sound = sfSound_create();
    all_game->death.buffer = sfSoundBuffer_createFromFile(PATH_TO_DEATH);
    sfSound_setBuffer(all_game->death.sound, all_game->death.buffer);
    all_game->win_sound.sound = sfSound_create();
    all_game->win_sound.buffer = sfSoundBuffer_createFromFile(PATH_WIN_SOUND);
    sfSound_setBuffer(all_game->win_sound.sound, all_game->win_sound.buffer);
}

void destroy_death_win_sound(all_game_t *all_game)
{
    sfSoundBuffer_destroy(all_game->death.buffer);
    sfSound_destroy(all_game->death.sound);
    sfSoundBuffer_destroy(all_game->win_sound.buffer);
    sfSound_destroy(all_game->win_sound.sound);
}
