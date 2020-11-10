/*
** EPITECH PROJECT, 2019
** menu
** File description:
** my runner
*/

#include "../include/my.h"

int get_event_menus(all_game_t all_game)
{
    while (sfRenderWindow_pollEvent(all_game.window, &all_game.event)) {
        switch (all_game.event.type) {
        case sfEvtKeyPressed :
            switch (all_game.event.key.code) {
            case sfKeySpace:
                return (SPACE_PRESSED);
            case sfKeyEscape:
                return (ESCAPE_PRESSED);
            }
            break;
        case sfEvtClosed :
            sfRenderWindow_close(all_game.window);
            break;
        }
    }
    return (0);
}

void pause_game(all_game_t all_game)
{
    int loop = 1;

    while (loop == 1 && sfRenderWindow_isOpen(all_game.window)) {
        put_all_sprite(all_game);
        sfRenderWindow_drawSprite(all_game.window, all_game.pause.sprite, 0);
        sfRenderWindow_display(all_game.window);
        switch (get_event_menus(all_game)) {
        case SPACE_PRESSED:
            loop = 0;
            break;
        case ESCAPE_PRESSED:
            sfRenderWindow_close(all_game.window);
        }
    }
}

void put_menu(all_game_t all_game)
{
    int loop = 1;
    int ret = 0;

    sfRenderWindow_setMouseCursorVisible(all_game.window, sfFalse);
    while (loop == 1 && sfRenderWindow_isOpen(all_game.window)) {
        sfRenderWindow_clear(all_game.window, sfBlack);
        sfRenderWindow_drawSprite(all_game.window, all_game.menu.menu, NULL);
        ret = get_event_menus(all_game);
        if (ret == SPACE_PRESSED)
            loop = 0;
        else if (ret == ESCAPE_PRESSED)
            sfRenderWindow_close(all_game.window);
        sfRenderWindow_display(all_game.window);
    }
}
