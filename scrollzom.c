/*
** EPITECH PROJECT, 2020
** gamefile
** File description:
** main
*/

#include "game.h"

static size_t count_nb_line(game_t *game, char **new_map)
{
    size_t i = 0;
    size_t x = 0;

    while (game->map[x] != NULL) {
        free(game->map[x]);
        x++;
    }
    free(game->map[x]);
    free(game->map);
    while (new_map[i] != NULL)
        i++;
    game->map = malloc(sizeof(char *) * (i + 1));
    return (i);
}

static void copy_in_map(game_t *game, char **new_map)
{
    size_t x = 0;
    size_t y = 0;
    size_t i = 0;

    x = count_nb_line(game, new_map);
    while (i != x) {
        game->map[i] = malloc(sizeof(char) * (my_strlen(new_map[i]) + 1));
        while (new_map[i][y] != '\0') {
            game->map[i][y] = new_map[i][y];
            y++;
        }
        free(new_map[i]);
        game->map[i][y] = '\0';
        y = 0;
        i++;
    }
    free(new_map);
    game->map[i] = NULL;
    game->map_size.x = i;
    game->map_size.y = my_strlen(game->map[0]);
}

static char **copy_black_cell(game_t *game, char **new_map)
{
    size_t x = game->map_size.x / 4;
    size_t y = game->map_size.y / 4;
    size_t sx = 0;
    size_t sy = 0;

    while (game->map[x] != NULL) {
        while (game->map[x][y] != '\0') {
            if (game->map[x][y] == BLACK && new_map[sx] != NULL)
                new_map[sx][sy] = BLACK;
            y++;
            sy++;
        }
        sx++;
        x++;
        y = game->map_size.y / 4;
        sy = 0;
    }
    return (new_map);
}

static char **fill_new_map(game_t *game, char **new_map)
{
    size_t x = 0;
    size_t i = 0;
    size_t y = my_strlen(game->map[i]) / 2;

    while (new_map[x] != NULL) {
        while (i != y) {
            new_map[x][i] = WHITE;
            i++;
        }
        new_map[x][i] = '\0';
        i = 0;
        x++;
    }
    new_map = copy_black_cell(game, new_map);
    return (new_map);
}

void my_scroll_zom(game_t *game)
{
    char **new_map = NULL;
    size_t x = 0;
    size_t i = 0;
    size_t y = (my_strlen(game->map[0]) / 2) + 1;

    while (game->map[x] != NULL)
        x++;
    x = x / 2;
    new_map = malloc(sizeof(char *) * (x + 1));
    if (new_map == NULL)
        exit (84);
    while (i != x) {
        new_map[i] = malloc(sizeof(char) * y);
        if (new_map == NULL)
            exit (84);
        i++;
    }
    new_map[i] = NULL;
    new_map = fill_new_map(game, new_map);
    copy_in_map(game, new_map);
}