/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** my.c
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return count;
}

int my_putchar(char c)
{
    return write(1, &c, 1);
}

int my_putstr(char *str)
{
    return write(1, str, my_strlen(str));
}

int my_strcmp(char const *s1, char const *s2)
{
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; s1[i] != '\0'; i++)
        count1 += s1[i];
    for (int i = 0; s2[i] != '\0'; i++)
        count2 += s2[i];
    if (count1 == count2){
        return 0;
    } else if (count1 > count2){
        return 1;
    } else {
        return -1;
    }
}

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] >= 65) && (str[i] <= 90))
            str[i] = str[i] + 32;
    return str;
}
