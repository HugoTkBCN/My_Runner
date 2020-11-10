/*
** EPITECH PROJECT, 2019
** collision
** File description:
** collision of the game
*/

#include "../include/my.h"

int check_collision(sfVector2f pos_runner, sfVector2f **pos_obstacle, int i)
{
    for (int y = 0; pos_obstacle[i][y].x; y++) {
        if (pos_runner.x + WIDTH_RUNNER >= pos_obstacle[i][y].x &&
            pos_runner.x <= pos_obstacle[i][y].x + WIDTH_BLOCK - 5 &&
            pos_runner.y + HEIGHT_RUNNER >= pos_obstacle[i][y].y &&
            pos_runner.y <= pos_obstacle[i][y].y + HEIGHT_BLOCK - 5)
            return (1);
    }
    return (0);
}

int collision(all_game_t all_game)
{
    sfVector2f pos_runner = all_game.runner.position;
    sfVector2f **pos_obstacle = malloc(sizeof(sfVector2f*) * 3);

    pos_obstacle[0] = all_game.pos_cube1;
    pos_obstacle[1] = all_game.pos_cube2;
    pos_obstacle[2] = all_game.pos_pic;
    for (int i = 0; i < 3; i++)
        if (check_collision(pos_runner, pos_obstacle, i) == 1)
            return (1);
    free(pos_obstacle);
    return (0);
}
