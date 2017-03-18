//
// Created by Tom BILLARD on 3/18/17.
//
#include "fdf.h"
int     ro_m(t_env *env)
{
    if (env->color.r1 - NB > 0  )
        env->color.r1 -= NB;
    return (0);
}

int     ro_p(t_env *env)
{
    if (env->color.r1 + NB < 255)
        env->color.r1 += NB;
    return (0);
}

int     rt_m(t_env *env)
{
    if (env->color.r2 - NB > 0  )
        env->color.r2 -= NB;
    return (0);
}

int     rt_p(t_env *env)
{
    if (env->color.r2 + NB < 255)
        env->color.r2 += NB;
    return (0);
}
