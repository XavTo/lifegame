/*
** EPITECH PROJECT, 2020
** copy
** File description:
** double_tab
*/

#include <stdlib.h>
#include <stddef.h>

static int my_count_tab_x(char **source)
{
    size_t i = 0;

    while (source[i] != NULL) {
        i++;
    }
    return (i);
}

static char *copy_tab_y(char *source, char *copy)
{
    size_t i = 0;
    size_t y = 0;

    while (source[y] != '\0')
        y++;
    copy = malloc(sizeof(char) * (y + 1));
    if (copy == NULL)
        return (NULL);
    while (i != y) {
        copy[i] = source[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

char **my_copy_double_tab(char **source, char **copy)
{
    int x = my_count_tab_x(source);
    size_t i = 0;

    copy = malloc(sizeof(char *) * (x + 1));
    if (copy == NULL)
        return (NULL);
    while (i != x) {
        copy[i] = copy_tab_y(source[i], copy[i]);
        if (copy[i] == NULL)
            return (NULL);
        i++;
    }
    copy[i] = NULL;
    return (copy);
}