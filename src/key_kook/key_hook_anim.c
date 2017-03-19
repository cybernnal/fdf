#include "fdf.h"

int		anim_ra(t_env *env)
{
    env->anim2 = !env->anim2;
    return (0);
}

int		anim_ro(t_env *env)
{
    env->anim = !env->anim;
    return (0);
}