#include "fdf.h"

Uint32		terra_color(t_env *e)
{
    int				s;
    int				z;

    if (e->up <= 0)
        z = (int)(e->min - e->up);
    else
        z = (int)(e->up + abs((int)e->min));
    z = z == 0 ? 1 : abs(z);
    s = (int)(abs((int)e->min) + e->max);
    return ((Uint32)((z * 255 / s) << 16) + ((z * 255 / s) << 8) + z * 255 / s);
}

Uint32		map_color(t_env *env)
{
    Uint32 min;
    Uint32 max;

    min = 0x000000;
    max = 0xffffff;
    return ((Uint32)L_C(env->tab[env->y][env->x],
                        env->min, env->max, min, max));
}

Uint32		custom_color(t_env *env)
{
    Uint32 r;
    Uint32 g;
    Uint32 b;

    r = (Uint32)L_C(env->tab[env->y][env->x], env->min, env->max,
                    env->color.r1, env->color.r2);
    g = (Uint32)L_C(env->tab[env->y][env->x], env->min, env->max,
                    env->color.g1, env->color.g2);
    b = (Uint32)L_C(env->tab[env->y][env->x], env->min, env->max,
                    env->color.b1, env->color.b2);
    return ((Uint32)((r << 16) + (g << 8) + b));
}

static Uint32		ign_color_2(int z2, t_env *e)
{
    if (z2 >= 75)
        return (0xc3a76b);
    if (z2 >= 50)
        return (0xded6a3);
    if (z2 >= 25)
        return (0xbdcc96);
    if (z2 >= 20)
        return (0xa8c68f);
    if (z2 >= 10)
        return (0x94bf8b);
    if (z2 > 0)
        return (0xacd0a5);
    if (e->up >= -10)
        return (0xd8f2fe);
    if (z2 > -50)
        return (0xb9e3ff);
    if (z2 > -75)
        return (0x96c9f0);
    else
        return (0x71abd8);
}

Uint32		ign_color(t_env *e)
{
    int				z2;

    z2 = (int)e->up;
    if (z2 >= 250)
        return (0xf5f4f2);
    if (z2 >= 225)
        return (0xe0ded8);
    if (z2 >= 200)
        return (0xcac3b8);
    if (z2 >= 175)
        return (0xbaae9a);
    if (z2 >= 150)
        return (0xac9a7c);
    if (z2 >= 125)
        return (0xaa8753);
    if (z2 >= 100)
        return (0xb9985a);
    return (ign_color_2(z2, e));
}
