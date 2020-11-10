/*
** EPITECH PROJECT, 2019
** create runner
** File description:
** runner
*/

#include "../../include/my.h"

game_object_t create_runner(sfIntRect rect, sfVector2f vector)
{
    game_object_t runner = create_object(PATH_TO_RUNNER_RUN,
                                        vector,
                                        rect);

    runner.type = RUNNER;
    runner.ptr_move = &move_runner;
    sfSprite_setPosition(runner.sprite, vector);
    return (runner);
}

game_object_t create_object(const char *path_to_spritesheet,
                            sfVector2f pos,
                            sfIntRect rect)
{
    game_object_t game_object;

    game_object.texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    game_object.rect = rect;
    game_object.rect2 = rect;
    game_object.position = pos;
    game_object.sprite = sfSprite_create();
    sfSprite_setTexture(game_object.sprite, game_object.texture, sfTrue);
    sfSprite_setTextureRect(game_object.sprite, game_object.rect);
    return (game_object);
}
