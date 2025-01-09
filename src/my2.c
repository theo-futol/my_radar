/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** my2.c
*/

#include "../include/my.h"

static int conversion(char c)
{
    char letter = 48;
    int i = 0;

    while (letter != c){
        i++;
        letter++;
    }
    return i;
}

static int value_to_return(int value, int last_value)
{
    if (value == 0)
        value = last_value;
    if (value > INT_MAX || value < INT_MIN)
        value = 0;
    return value;
}

static float value_to_return_f(float value, float last_value)
{
    if (value == 0)
        value = last_value;
    if ((int)value > INT_MAX || (int)value < INT_MIN)
        value = 0;
    return value;
}

int my_getnbr(char const *str, int stop_value)
{
    int value = 0;
    int last_value = 0;
    int multiplication = 1;

    for (int i = my_strlen(str) - 1; i != stop_value; i--){
        if (str[i] == '-')
            value *= -1;
        if ((str[i] < '0' || str[i] > '9') && value != 0){
            last_value = value;
            value = 0;
            multiplication = 1;
        }
        if (str[i] >= '0' && str[i] <= '9'){
            value += conversion(str[i]) * multiplication;
            multiplication *= 10;
        }
    }
    return value_to_return(value, last_value);
}

static float get_float_value(char const *str, int i, int end)
{
    float new_value = 0.0;
    int mul = 1;

    for (i = i - 1; i != end; i--){
        new_value += conversion(str[i]) * mul;
        mul *= 10;
    }
    return new_value;
}

static void init_last_value(float *last_value, float *value,
    int *multiplication)
{
    (*last_value) = *value;
    (*value) = 0;
    (*multiplication) = 1;
}

float my_getfloat(char const *str, int stop_value)
{
    float value = 0.0;
    float last_value = 0.0;
    int multiplication = 1;

    for (int i = my_strlen(str) - 1; i != stop_value; i--){
        if (str[i] == '-')
            value *= -1;
        if (str[i] == '.'){
            value /= multiplication;
            value += get_float_value(str, i, stop_value);
            break;
        }
        if ((str[i] < '0' || str[i] > '9') && value != 0)
            init_last_value(&last_value, &value, &multiplication);
        if (str[i] >= '0' && str[i] <= '9'){
            value += conversion(str[i]) * multiplication;
            multiplication *= 10;
        }
    }
    return value_to_return_f(value, last_value);
}
