//
// Created by Tom BILLARD on 3/18/17.
//
#include "fdf.h"

int     rt_i(t_env *env)
{
    env->rad += env->mrad;
    return (0);
}

int     rt_d(t_env *env)
{
    env->rad -= env->mrad;
    return (0);
}



int     rtv_i(t_env *env)
{
    env->mrad += 0.01;
    return (0);
}

int     rtv_d(t_env *env)
{
    env->mrad -= 0.01;
    return (0);
}