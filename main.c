/*
** EPITECH PROJECT, 2018
** main
** File description:
** bootstrap
*/

#include "include/my.h"

int check_arg(int ac, char **av)
{
    if (ac != 2) {
        my_putstr("./my_runner: bad arguments: 0 given but 1 is required\n");
        my_putstr("retry with -h\n");
        return (84);
    } else if (av[1][0] == '-' && av[1][1] == 'h' && my_strlen(av[1]) == 2) {
        my_putstr("Finite runner created with CSFML\n\nUSAGE\n");
        my_putstr(" ./my_runner map.txt\n\n\nOPTIONS\n");
        my_putstr(" -h\t\tprint the usage and quit.\n\nUSER INTERACTIONS\n");
        my_putstr(" SPACE_KEY\tjump.\n ESCAPE_KEY\tpause.\n");
        return (1);
    }
    return (0);
}

char **get_map(char *file_path)
{
    char **map = malloc(sizeof(char *) * 100);
    int fd = open(file_path, O_RDONLY);
    char *s;
    int i = 0;

    s = get_next_line(fd);
    while (s) {
        map[i++] = my_strdup(s);
        s = get_next_line(fd);
    }
    map[i] = NULL;
    close(fd);
    return (map);
}

int run_game(int ac, char **av)
{
    all_game_t all_game;
    int ret = check_arg(ac, av);
    sfMusic *music = sfMusic_createFromFile(PATH_TO_MUSIC);

    if (ret == EXIT_ERROR)
        return (EXIT_ERROR);
    else if (ret == 1)
        return (0);
    all_game.map = get_map(av[1]);
    all_game = create_main_struct(all_game, all_game.map);
    sfMusic_play(music);
    sfMusic_setVolume(music, 25);
    sfMusic_setLoop(music, sfTrue);
    my_runner(all_game);
    destroy_game(&all_game);
    sfMusic_destroy(music);
    return (0);
}

int is_display(char **envp)
{
    for (int i = 0; envp[i]; i++) {
        if (envp[i][0] == 'D' && envp[i][1] == 'I')
            return (1);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    int ret = 0;

    if (env[0] && is_display(env) == 1)
        ret = run_game(ac, av);
    else
        return (EXIT_ERROR);
    return (ret);
}
