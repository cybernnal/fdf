//
// Created by Tom BILLARD on 3/18/17.
//
#include "fdf.h"
int    go_left(t_env *env)
{
    int nb = (env->ratio > 10 ? 1 : 50);

    env->winx += nb;
    return (0);
}

int    go_right(t_env *env)
{
    int nb = (env->ratio > 10 ? 1 : 50);

    env->winx -= nb;
    return (0);
}

int    go_top(t_env *env)
{
    int nb = (env->ratio > 10 ? 1 : 50);

    env->winy += nb;
    return (0);
}

int    go_bot(t_env *env)
{
    int nb = (env->ratio > 10 ? 1 : 50);

    env->winy -= nb;
    return (0);
}
