/*
** EPITECH PROJECT, 2019
** create wallpaper
** File description:
** runner
*/

#include "../../include/my.h"

game_object_t *create_array_wallpaper(sfIntRect rect, sfVector2f vector)
{
    game_object_t back_ground = create_object(PATH_TO_BACKGROUND,
                                                vector,
                                                rect);
    game_object_t middle_ground = create_object(PATH_TO_MIDDLEGROUND,
                                                vector,
                                                rect);
    game_object_t for_ground = create_object(PATH_TO_FORGROUND, vector, rect);
    game_object_t *wall_paper = malloc(sizeof(game_object_t) * 3);

    wall_paper[0] = back_ground;
    wall_paper[1] = middle_ground;
    wall_paper[2] = for_ground;
    wall_paper[0].speed = 1;
    wall_paper[1].speed = 2;
    wall_paper[2].speed = 15;
    for (int i = 0; i < 3; i++) {
        wall_paper[i].type = WALLPAPER;
        wall_paper[i].ptr_move = &move_wallpaper;
    }
    return (wall_paper);
}
