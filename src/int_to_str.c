/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** int_to_str.c
*/

#include "../include/my.h"

static int get_divisor(float nb, int *max_str)
{
    int divisor = 1;

    while (nb >= 10){
        nb /= 10;
        divisor *= 10;
        (*max_str)++;
    }
    return divisor;
}

char *conversion_int_char(int nb)
{
    float number = (float)nb;
    int max_str = 1;
    int first_divisor = get_divisor(number, &max_str);
    char *str = malloc(sizeof(char) * (max_str + 1));
    int i = 0;

    if (str == NULL)
        return NULL;
    str[i] = (int)(number / first_divisor) + '0';
    number = (number / first_divisor) - (int)(number / first_divisor);
    for (i = 1; max_str - 1 > 0; i++){
        str[i] = (int)(number * 10 + 0.000005) + '0';
        number = (number - (int)(number)) * 10 + 0.000005;
        max_str--;
    }
    str[i] = '\0';
    return str;
}
