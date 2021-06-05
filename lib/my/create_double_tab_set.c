/*
** EPITECH PROJECT, 2020
** create double tab
** File description:
** copy fonction
*/

#include <stddef.h>
#include <stdlib.h>

char *fill_tab(char *tab, size_t y, char val)
{
    size_t i = 0;

    tab = malloc(sizeof(char) * (y + 1));
    if (tab == NULL)
        return (NULL);
    while (i != y) {
        tab[i] = val;
        i++;
    }
    tab[i] = '\0';
    return (tab);
}

char **create_double_tab_set(char **tab, size_t x, size_t y, char val)
{
    size_t i = 0;

    tab = malloc(sizeof(char *) * (x + 1));
    if (tab == NULL)
        return (NULL);
    while (i != x) {
        tab[i] = fill_tab(tab[i], y, val);
        if (tab[i] == NULL)
            return (NULL);
        i++;
    }
    tab[i] = NULL;
    return (tab);
}