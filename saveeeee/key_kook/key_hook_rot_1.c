//
// Created by Tom BILLARD on 3/18/17.
//
#include "fdf.h"
int     ro_i(t_env *env)
{
    env->rot += env->mrot;
    return (0);
}

int     ro_d(t_env *env)
{
    env->rot -= env->mrot;
    return (0);
}

int     rov_i(t_env *env)
{
    env->mrot += 0.01;
    return (0);
}

int     rov_d(t_env *env)
{
    env->mrot -= 0.01;
    return (0);
}
