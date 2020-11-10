/*
** EPITECH PROJECT, 2018
** wallpaper
** File description:
** runner
*/

#include "../include/my.h"

void move_wallpaper(game_object_t *wall_paper)
{
    wall_paper->rect.top = 0;
    wall_paper->rect.left += wall_paper->speed;
    wall_paper->rect.width = WIDTH_WP - wall_paper->rect.left;
    if (wall_paper->rect.left >= WIDTH_WP) {
        wall_paper->rect.left = 0;
        wall_paper->rect.width = WIDTH_WP;
    }
    wall_paper->rect.height = HEIGHT_WP;
    wall_paper = move_wallpaper2(wall_paper);
}

game_object_t *move_wallpaper2(game_object_t *wall_paper)
{
    wall_paper->rect2.top = 0;
    wall_paper->rect2.left = 0;
    wall_paper->rect2.width = WIDTH_WP - wall_paper->rect.width;
    wall_paper->rect2.height = HEIGHT_WP;
    return (wall_paper);
}

void display_wallpaper(sfRenderWindow *window, game_object_t *wall_paper)
{
    for (int i = 0; i < 3; i++) {
        wall_paper[i].position.x = 0;
        sfSprite_setPosition(wall_paper[i].sprite, wall_paper[i].position);
        sfSprite_setTextureRect(wall_paper[i].sprite, wall_paper[i].rect);
        sfRenderWindow_drawSprite(window, wall_paper[i].sprite, NULL);
        wall_paper[i].position.x = wall_paper[i].rect.width;
        sfSprite_setPosition(wall_paper[i].sprite, wall_paper[i].position);
        sfSprite_setTextureRect(wall_paper[i].sprite, wall_paper[i].rect2);
        sfRenderWindow_drawSprite(window, wall_paper[i].sprite, NULL);
    }
}
