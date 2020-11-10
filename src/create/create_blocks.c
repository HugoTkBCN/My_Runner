/*
** EPITECH PROJECT, 2019
** create blocks
** File description:
** my runner
*/

#include "../../include/my.h"

obstacle_t *create_array_obstacle(sfVector2f vector)
{
    obstacle_t block_1 = create_obstacle(PATH_TO_BLOCK_1, vector);
    obstacle_t block_2 = create_obstacle(PATH_TO_BLOCK_2, vector);
    obstacle_t pic = create_obstacle(PATH_TO_PIC, vector);
    obstacle_t *obstacle = malloc(sizeof(obstacle_t) * 3);

    obstacle[0] = block_1;
    obstacle[1] = block_2;
    obstacle[2] = pic;
    obstacle[0].type = BLOCKS;
    obstacle[1].type = BLOCKS;
    obstacle[2].type = PIC;
    return (obstacle);
}

obstacle_t create_obstacle(const char *path_to_spritesheet, sfVector2f vector)
{
    obstacle_t obstacle;

    obstacle.texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    obstacle.sprite = sfSprite_create();
    obstacle.position = vector;
    sfSprite_setTexture(obstacle.sprite, obstacle.texture, sfTrue);
    return (obstacle);
}
