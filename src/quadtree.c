/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** quatree.c
*/

#include "../include/my.h"

static int plane_in_qt(planes_t p1, sfVector2f pos, sfVector2f size)
{
    if (p1.is_avail != 1)
        return 0;
    return sqrt(pow((p1.pos.y + 10) - (pos.y + size.y), 2) +
    pow((p1.pos.x + 10) - (pos.x + size.x), 2));
}

static int create_my_qt(main_struct_t *main, quadtree_t *qt, sfVector2f pos,
    sfVector2f size)
{
    qt->zone = pos;
    qt->size = size;
    qt->len_plane = 0;
    qt->id = my_alloc_qt_id(NULL, 1, 0);
    if (qt->id == NULL)
        return 84;
    for (int i = 0; i < main->len_planes; i++){
        if (plane_in_qt(main->all_planes[i], pos, size) == 0)
            continue;
        qt->id[qt->len_plane] = i;
        qt->len_plane++;
        qt->id = my_alloc_qt_id(qt->id, qt->len_plane + 1, qt->len_plane);
        if (qt->id == NULL)
            return 84;
    }
    qt->rec = create_rec(pos, NULL, size, sfTransparent);
    if (qt->rec == NULL)
        return 84;
    return 0;
}

int init_qt(main_struct_t *main)
{
    main->my_qt = my_alloc_qt(main->my_qt, 4, 0);
    if (main->my_qt == NULL)
        return 84;
    if (create_my_qt(main, &main->my_qt[0], (sfVector2f){0, 0}, (sfVector2f){
    960, 540}) == 84 || create_my_qt(main, &main->my_qt[1], (sfVector2f){960, 0
    }, (sfVector2f){960, 540}) == 84 || create_my_qt(main, &main->my_qt[2], (
    sfVector2f){0, 540}, (sfVector2f){960, 540}) == 84 || create_my_qt(main,
    &main->my_qt[3], (sfVector2f){960, 540}, (sfVector2f){960, 540}) == 84)
        return 84;
    main->len_qt = 3;
    return 0;
}
