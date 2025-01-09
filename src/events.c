/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** events.c
*/

#include "../include/my.h"

static int is_same_color(sfColor value1)
{
    return value1.a == sfRed.a && value1.b == sfRed.b && value1.g == sfRed.g
    && value1.r == sfRed.r;
}

static void switch_visibility_s(main_struct_t *data)
{
    data->display_sprt = !data->display_sprt;
    if (data->display_sprt)
        for (int i = 0; i < data->len_planes; i++)
            sfRectangleShape_setFillColor(data->all_planes[i].rec, sfWhite);
    else
        for (int i = 0; i < data->len_planes; i++)
            sfRectangleShape_setFillColor(data->all_planes[i].rec,
            sfTransparent);
}

static void switch_visibility_l(main_struct_t *data)
{
    data->display_qt = !data->display_qt;
    for (int i = 0; i < data->len_planes; i++){
        if (is_same_color(sfRectangleShape_getOutlineColor(data->all_planes[i].
            rec)))
            sfRectangleShape_setOutlineColor(data->all_planes[i].rec,
            sfTransparent);
        else
            sfRectangleShape_setOutlineColor(data->all_planes[i].rec, sfRed);
    }
    for (int i = 0; i < data->len_towers; i++){
        if (is_same_color(sfCircleShape_getOutlineColor(data->all_towers[i]
            .circle)))
            sfCircleShape_setOutlineColor(data->all_towers[i].circle,
            sfTransparent);
        else
            sfCircleShape_setOutlineColor(data->all_towers[i].circle, sfRed
            );
    }
}

void manage_event(main_struct_t *data)
{
    sfEvent event = {0};

    while (sfRenderWindow_pollEvent(data->wind.wind, &event)){
        if (event.type == sfEvtClosed || (event.key.code == sfKeyQ && event.key
            .type == 5))
            sfRenderWindow_close(data->wind.wind);
        if (event.key.code == sfKeyS && event.key.type == 5)
            switch_visibility_s(data);
        if (event.key.code == sfKeyL && event.key.type == 5)
            switch_visibility_l(data);
    }
}
