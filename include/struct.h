/*
** EPITECH PROJECT, 2019
** structure
** File description:
** all mystruct
*/

typedef struct text{
    sfText *text;
    sfVector2f pos;
    sfFont *font;
} text_t;

typedef enum {
    WALLPAPER,
    RUNNER,
    BLOCKS,
    PIC
} type_object_t;

typedef struct obstacle{
    type_object_t type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
} obstacle_t;

typedef struct game_object{
    type_object_t type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
    sfIntRect rect2;
    float speed;
    void (*ptr_move)();
} game_object_t;

typedef struct pause{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
} pause_t;

typedef struct menu{
    sfSprite *menu;
    sfTexture *texture;
} menu_t;

typedef struct sound{
    sfSoundBuffer *buffer;
    sfSound *sound;
} sound_t;

typedef struct all_game{
    sfRenderWindow *window;
    char **map;
    menu_t menu;
    int score;
    sound_t death;
    sound_t win_sound;
    text_t score_text;
    text_t score_game;
    pause_t pause;
    pause_t lose;
    pause_t win;
    sfEvent event;
    game_object_t *wall_paper;
    game_object_t runner;
    int runner_up;
    obstacle_t *obstacle;
    sfVector2f *pos_cube1;
    sfVector2f *pos_cube2;
    sfVector2f *pos_pic;
    int b_put;
    int nbr_game;
    int len_map;
} all_game_t;
