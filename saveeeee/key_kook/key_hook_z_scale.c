//
// Created by Tom BILLARD on 3/18/17.
//

#include "fdf.h"
int     zo_i(t_env *env)
{
    env->cz += 0.05;
    return (0);
}

int     zo_d(t_env *env)
{
    env->cz -= 0.05;
    return (0);
}
