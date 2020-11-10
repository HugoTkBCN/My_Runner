/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** bootstrap my runner
*/

#include "lib.h"
#include "get_next_line.h"
#include "define.h"
#include "struct.h"

int my_runner(all_game_t);
obstacle_t *create_array_obstacle(sfVector2f);
obstacle_t create_obstacle(const char *, sfVector2f);
void destroy_obstacle(obstacle_t *obstacle);
void put_blocks(all_game_t *all_game, int choice);
void display_runner(sfRenderWindow *, game_object_t);
void display_wallpaper(sfRenderWindow *, game_object_t *);
void move_wallpaper(game_object_t *);
game_object_t *move_wallpaper2(game_object_t *);
int analyse_events(all_game_t);
sfRenderWindow *open_window(int, int, char *);
game_object_t create_object(const char *, sfVector2f, sfIntRect);
game_object_t *create_array_wallpaper(sfIntRect, sfVector2f);
game_object_t create_runner(sfIntRect, sfVector2f);
void destroy_object(game_object_t *);
void my_putchar(char);
void my_putstr(char const *);
void my_put_nbr(int);
void runner_run(all_game_t *);
all_game_t create_main_struct(all_game_t, char **map);
void destroy_game(all_game_t *);
int my_strlen(char *);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char *my_strdup(char *src);
char *my_strcpy(char *dest, char *src);
void make_the_jump(all_game_t *all_game);
void move_runner(game_object_t *runner);
sfVector2f *get_coord(char **map, char type);
int collision(all_game_t);
void put_score(all_game_t all_game);
int str_to_int(char *nbr);
char *int_to_str(int nbr);
char *my_revstr(char *str);
void create_score(all_game_t *all_game);
void destroy_text(text_t *text);
void create_pause(pause_t *pause, char *path);
void create_menu(menu_t *menu);
int get_event_menus(all_game_t all_game);
void put_all_sprite(all_game_t all_game);
void put_menu(all_game_t all_game);
void restart(all_game_t *all_game, int win);
void init_game(all_game_t *all_game);
void pause_game(all_game_t all_game);
void do_move(all_game_t *all_game);
void create_death_win_sound(all_game_t *all_game);
void destroy_death_win_sound(all_game_t *all_game);
