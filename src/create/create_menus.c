/*
** EPITECH PROJECT, 2019
** create menu
** File description:
** runner
*/

#include "../../include/my.h"

void create_pause(pause_t *pause, char *path)
{
    pause->texture = sfTexture_createFromFile(path, NULL);
    pause->position = (sfVector2f){X_PAUSE, Y_PAUSE};
    pause->sprite = sfSprite_create();
    sfSprite_setTexture(pause->sprite, pause->texture, sfTrue);
    sfSprite_setPosition(pause->sprite, pause->position);
}

void create_menu(menu_t *menu)
{
    menu->texture = sfTexture_createFromFile(PATH_TO_MENU, NULL);
    menu->menu = sfSprite_create();
    sfSprite_setTexture(menu->menu, menu->texture, sfTrue);
}
