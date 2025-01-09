/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** my_alloc.c
*/

#include "../include/my.h"

towers_t *my_alloc_towers(towers_t *ptr, size_t new_size, size_t old_size)
{
    towers_t *new_pointer = NULL;

    new_size *= sizeof(towers_t);
    if (new_size == 0){
        free(ptr);
        return NULL;
    }
    if (ptr == NULL)
        return malloc(new_size);
    new_pointer = malloc(new_size);
    if (new_pointer == NULL)
        return NULL;
    for (size_t i = 0; i < old_size; i++)
        new_pointer[i] = ptr[i];
    free(ptr);
    return new_pointer;
}

planes_t *my_alloc_planes(planes_t *ptr, size_t new_size, size_t old_size)
{
    planes_t *new_pointer = NULL;

    new_size *= sizeof(planes_t);
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL)
        return malloc(new_size);
    new_pointer = malloc(new_size);
    if (new_pointer == NULL)
        return NULL;
    for (size_t i = 0; i < old_size; i++)
        new_pointer[i] = ptr[i];
    free(ptr);
    return new_pointer;
}

quadtree_t *my_alloc_qt(quadtree_t *ptr, size_t new_size, size_t old_size)
{
    quadtree_t *new_pointer = NULL;

    new_size *= sizeof(quadtree_t);
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL)
        return malloc(new_size);
    new_pointer = malloc(new_size);
    if (new_pointer == NULL)
        return NULL;
    for (size_t i = 0; i < old_size; i++)
        new_pointer[i] = ptr[i];
    free(ptr);
    return new_pointer;
}

int *my_alloc_qt_id(int *ptr, size_t new_size, size_t old_size)
{
    int *new_pointer = NULL;

    new_size *= sizeof(int);
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL)
        return malloc(new_size);
    new_pointer = malloc(new_size);
    if (new_pointer == NULL)
        return NULL;
    for (size_t i = 0; i < old_size; i++)
        new_pointer[i] = ptr[i];
    free(ptr);
    return new_pointer;
}
