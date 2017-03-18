//
// Created by Tom BILLARD on 3/18/17.
//
#include "fdf.h"
int    zoom_in(t_env *env)
{
    env->ratio += env->rzoom;
    return (0);
}

int    zoom_out(t_env *env)
{
    if (env->ratio - env->rzoom > 0)
        env->ratio -= env->rzoom;
    return (0);
}

int    zoom_p(t_env *env)
{
    env->rzoom += 0.1;
    return (0);
}

int    zoom_m(t_env *env)
{
    if (env->rzoom - 0.1 > 0)
        env->rzoom -= 0.1;
    return (0);
}