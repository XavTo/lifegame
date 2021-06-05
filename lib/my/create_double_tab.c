/*
** EPITECH PROJECT, 2020
** create double tab
** File description:
** copy fonction
*/

#include <stddef.h>
#include <stdlib.h>

char **create_double_tab(char **tab, size_t x, size_t y)
{
    size_t i = 0;

    tab = malloc(sizeof(char *) * (x + 1));
    if (tab == NULL)
        return (NULL);
    while (i != x) {
        tab[i] = malloc(sizeof(char) * (y + 1));
        if (tab[i] == NULL)
            return (NULL);
        i++;
    }
    tab[i] = NULL;
    return (tab);
}