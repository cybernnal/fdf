#include "fdf.h"

int		config_set(t_env *env)
{
    env->config = !env->config;
    return (0);
}