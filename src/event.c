/*
** EPITECH PROJECT, 2018
** bootstrap
** File description:
** my_hunter
*/

#include "../include/my.h"

void restart(all_game_t *all_game, int win)
{
    int loop = 1;
    int ret = 0;

    while (loop == 1 && sfRenderWindow_isOpen(all_game->window)) {
        put_all_sprite(*all_game);
        if (win == 1)
            sfRenderWindow_drawSprite(all_game->window,
                                        all_game->win.sprite, NULL);
        else
            sfRenderWindow_drawSprite(all_game->window,
                                        all_game->lose.sprite, NULL);
        sfRenderWindow_display(all_game->window);
        ret = get_event_menus(*all_game);
        if (ret == SPACE_PRESSED) {
            init_game(all_game);
            loop = 0;
        } else if (ret == ESCAPE_PRESSED)
            sfRenderWindow_close(all_game->window);
    }
}

int analyse_events(all_game_t all_game)
{
    while (sfRenderWindow_pollEvent(all_game.window, &all_game.event)) {
        switch (all_game.event.type) {
        case sfEvtKeyPressed :
            if (all_game.event.key.code == sfKeySpace)
                return (SPACE_PRESSED);
            else if (all_game.event.key.code == sfKeyEscape)
                pause_game(all_game);
            break;
        case sfEvtClosed :
            sfRenderWindow_close(all_game.window);
            break;
        }
    }
    return (0);
}
