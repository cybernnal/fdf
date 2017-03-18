//
// Created by tom billard on 18/03/2017.
//

#include "fdf.h"

void    ft_end(t_env *env)
{
    int i;

    i = 0;
    while (i < env->line)
    {
        free(env->map[i]);
        free(env->tab[i]);
        i++;
    }
    free(env->map);
    free(env->tab);
    free(env->w);
    exit (0);
}