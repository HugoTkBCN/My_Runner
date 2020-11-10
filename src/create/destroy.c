/*
** EPITECH PROJECT, 2019
** destroy
** File description:
** destroy
*/

#include "../../include/my.h"

void destroy_text(text_t *text)
{
    sfFont_destroy(text->font);
    sfText_destroy(text->text);
}

void destroy_menu_pause(all_game_t *all_game)
{
    sfSprite_destroy(all_game->menu.menu);
    sfTexture_destroy(all_game->menu.texture);
    sfSprite_destroy(all_game->pause.sprite);
    sfTexture_destroy(all_game->pause.texture);
    sfSprite_destroy(all_game->lose.sprite);
    sfTexture_destroy(all_game->lose.texture);
    sfSprite_destroy(all_game->win.sprite);
    sfTexture_destroy(all_game->win.texture);
}

void destroy_game(all_game_t *all_game)
{
    destroy_object(&all_game->wall_paper[0]);
    destroy_object(&all_game->wall_paper[1]);
    destroy_object(&all_game->wall_paper[2]);
    destroy_object(&all_game->runner);
    destroy_obstacle(&all_game->obstacle[0]);
    destroy_obstacle(&all_game->obstacle[1]);
    destroy_obstacle(&all_game->obstacle[2]);
    destroy_text(&all_game->score_text);
    destroy_text(&all_game->score_game);
    free(*all_game->map);
    destroy_menu_pause(all_game);
    destroy_death_win_sound(all_game);
    free(all_game->pos_cube1);
    free(all_game->pos_cube2);
    free(all_game->pos_pic);
}

void destroy_object(game_object_t *game_object)
{
    sfTexture_destroy(game_object->texture);
    sfSprite_destroy(game_object->sprite);
}

void destroy_obstacle(obstacle_t *obstacle)
{
    sfTexture_destroy(obstacle->texture);
    sfSprite_destroy(obstacle->sprite);
}
