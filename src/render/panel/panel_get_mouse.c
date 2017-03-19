#include "panel.h"

static int      g_red(int x, int y, int off, t_env *env)
{
    int x0;

    x0 = CONF_X0 + MARGE / 2;
    if (x > (L_C(env->color.r1, 0, 255, 0, SIZE) + x0) - off &&
        x < (L_C(env->color.r1, 0, 255, 0, SIZE) + x0) + off)
        return (0);
    if (x > (L_C(env->color.r2, 0, 255, 0, SIZE) + x0) - off &&
        x < (L_C(env->color.r2, 0, 255, 0, SIZE) + x0) + off)
        return (1);
    return (-42);
}

static int      g_green(int x, int y, int off, t_env *env)
{
    int x0;

    x0 = CONF_X0 + MARGE / 2;
    if (x > (L_C(env->color.g1, 0, 255, 0, SIZE) + x0) - off &&
        x < (L_C(env->color.g1, 0, 255, 0, SIZE) + x0) + off)
        return (2);
    if (x > (L_C(env->color.g2, 0, 255, 0, SIZE) + x0) - off &&
        x < (L_C(env->color.g2, 0, 255, 0, SIZE) + x0) + off)
        return (3);
    return (-42);
}

static int      g_blue(int x, int y, int off, t_env *env)
{
    int x0;

    x0 = CONF_X0 + MARGE / 2;
    if (x > (L_C(env->color.b1, 0, 255, 0, SIZE) + x0) - off &&
        x < (L_C(env->color.b1, 0, 255, 0, SIZE) + x0) + off)
        return (4);
    if (x > (L_C(env->color.b2, 0, 255, 0, SIZE) + x0) - off &&
        x < (L_C(env->color.b2, 0, 255, 0, SIZE) + x0) + off)
        return (5);
    return (-42);
}

static int      get_new_curs(int x, int y, t_env *env)
{
    int off;

    off = CUR_S;
    if (x < CONF_X0 || x > WIN_X)
        return (-42);
    if (y > MARGE - off && y < MARGE + off)
        return (g_red(x, y, off, env));
    if (y > MARGE - (off) + BT && y < MARGE + (off) + BT)
        return (g_green(x, y, off, env));
    if (y > MARGE - (off) + BT * 2 && y < MARGE + (off) + BT * 2)
        return (g_blue(x, y, off, env));
    return (-42);
}

void      mouse_hit(t_env *env)
{
    static int hit = -42;
    int x;
    int y;

    x = 0;
    y = 0;
    if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT))
    {
        if (hit == -42)
            hit = get_new_curs(x, y, env);
        else
            hit = slide_current(x, env, hit);
    }
    else
        hit = -42;
}