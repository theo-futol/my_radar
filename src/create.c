/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** create.c
*/

#include "../include/my.h"

sfCircleShape *create_circle(sfVector2f pos, float radius)
{
    sfCircleShape *my_circle = sfCircleShape_create();

    if (my_circle == NULL)
        return NULL;
    pos.x += 16 - radius;
    pos.y += 20 - radius;
    sfCircleShape_setPosition(my_circle, pos);
    sfCircleShape_setRadius(my_circle, radius);
    sfCircleShape_setOutlineThickness(my_circle, 1.0);
    sfCircleShape_setOutlineColor(my_circle, sfRed);
    sfCircleShape_setFillColor(my_circle, sfTransparent);
    return my_circle;
}

sfRectangleShape *create_rec(sfVector2f pos, sfTexture *text, sfVector2f size,
    sfColor fillColor)
{
    sfRectangleShape *my_rec = sfRectangleShape_create();

    if (my_rec == NULL)
        return NULL;
    sfRectangleShape_setPosition(my_rec, pos);
    sfRectangleShape_setOutlineThickness(my_rec, 1.0);
    sfRectangleShape_setOutlineColor(my_rec, sfRed);
    sfRectangleShape_setFillColor(my_rec, fillColor);
    if (text != NULL)
        sfRectangleShape_setTexture(my_rec, text, sfTrue);
    sfRectangleShape_setSize(my_rec, size);
    return my_rec;
}

sfSprite *create_sprt(sfTexture *text, char type)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = (sfVector2f){1, 1};

    if (sprite == NULL)
        return NULL;
    if (type == 'T')
        scale = (sfVector2f){0.07, 0.07};
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setScale(sprite, scale);
    return sprite;
}
