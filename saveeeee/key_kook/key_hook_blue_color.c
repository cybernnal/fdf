//
// Created by Tom BILLARD on 3/18/17.
//

#include "fdf.h"

int     bo_m(t_env *env)
{


    if (env->color.b1 - NB > 0)
        env->color.b1 -= NB;
    return (0);
}

int     bo_p(t_env *env)
{
    if (env->color.b1 + NB < 255)
        env->color.b1 += NB;
    return (0);
}

int     bt_m(t_env *env)
{
    if (env->color.b2 - NB > 0)
        env->color.b2 -= NB;
    return (0);
}

int     bt_p(t_env *env)
{
    if (env->color.b2 + NB < 255)
        env->color.b2 += NB;
    return (0);
}
