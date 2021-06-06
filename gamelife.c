/*
** EPITECH PROJECT, 2020
** gamefile
** File description:
** main
*/

#include "game.h"

static void init_stuct(game_t *game)
{
    sfVideoMode video_m = {game->wd_size.x, game->wd_size.y, 32};

    game->start = true;
    game->pause = false;
    game->end = false;
    game->scroll = false;
    game->speed = 300000;
    game->cycle = 0;
    game->window = sfRenderWindow_create(
            video_m, "Game Life", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 120);
}

static void destructor(game_t *game)
{
    size_t x = 0;

    while (game->map[x] != NULL) {
        free(game->map[x]);
        x++;
    }
    free(game->map[x]);
    free(game->map);
    sfClock_destroy(game->clock);
    sfRenderWindow_close(game->window);
    sfRenderWindow_destroy(game->window);
}

int main(int ac, char **av)
{
    game_t game;

    game.wd_size.x = 1080;
    game.wd_size.y = 720;
    game.map_size.x = 30;
    game.map_size.y = 30;
    if (ac == 3 && my_str_isnum(av[1]) == 1 && my_str_isnum(av[2]) == 1) {
        game.map_size.x = my_getnbr(av[1]);
        game.map_size.y = my_getnbr(av[2]);
    }
    game.map = create_double_tab_set(
        game.map, game.map_size.x, game.map_size.y, WHITE);
    if (game.map == NULL)
        return (84);
    init_stuct(&game);
    game_loop(&game);
    destructor(&game);
    return (0);
}