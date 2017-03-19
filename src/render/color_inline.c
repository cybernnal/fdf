#include "fdf.h"

Uint32		  custom_color_il(t_env *env, Uint32 c1, int i)
{
    Uint32 r;
    Uint32 g;
    Uint32 b;
    float           up;

    if (env->col != 3 || !env->il)
        return (c1);
    if (env->pos == 1 && env->x + 1 < env->mod)
        up = env->tab[env->y][env->x + 1];
    else if ((env->pos == 2 && env->y + 1 < env->line))
        up = env->tab[env->y + 1][env->x];
    else
        up = env->tab[env->y][env->x];
    r = (Uint32)L_C(up, env->min, env->max, env->color.r1, env->color.r2);
    r = (Uint32)L_C(i, 0, env->ratio, c1 & 0xff0000, r);
    g = (Uint32)L_C(up, env->min, env->max, env->color.g1, env->color.g2);
    g = (Uint32)L_C(i, 0, env->ratio, c1 & 0xff00, g);
    b = (Uint32)L_C(up, env->min, env->max, env->color.b1, env->color.b2);
    b = (Uint32)L_C(i, 0, env->ratio, c1 & 0xff, b);
    return ((Uint32)((r << 16) + (g << 8) + b));
}