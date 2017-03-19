#include "panel.h"

static void draw_red_curs(t_env *env, t_window *w)
{
    int off;
    t_corr c;
    int x0;

    x0 = CONF_X0 + MARGE / 2;
    c.x = L_C(env->color.r1, 0, 255, 0, SIZE) + x0;
    c.y = MARGE;
    off = CUR_S;
    while (off > 0)
        drawcircle(c, off--, 0xf49b9b, w);
    c.x = L_C(env->color.r2, 0, 255, 0, SIZE) + x0;
    off = CUR_S;
    while (off > 0)
        drawcircle(c, off--, 0xfd4141, w);
}

static void draw_green_curs(t_env *env, t_window *w)
{
    int off;
    t_corr c;
    int x0;

    x0 = CONF_X0 + MARGE / 2;
    c.x = L_C(env->color.g1, 0, 255, 0, SIZE) + x0;
    c.y = MARGE + BT;
    off = CUR_S;
    while (off > 0)
        drawcircle(c, off--, 0xd5ffd6, w);
    c.x = L_C(env->color.g2, 0, 255, 0, SIZE) + x0;
    off = CUR_S;
    while (off > 0)
        drawcircle(c, off--, 0x5efb60, w);
}

static void draw_blue_curs(t_env *env, t_window *w)
{
    int off;
    t_corr c;
    int x0;

    x0 = CONF_X0 + MARGE / 2;
    c.x = L_C(env->color.b1, 0, 255, 0, SIZE) + x0;
    c.y = MARGE + BT * 2;
    off = CUR_S;
    while (off > 0)
        drawcircle(c, off--, 0x9794f6, w);
    c.x = L_C(env->color.b2, 0, 255, 0, SIZE) + x0;
    off = CUR_S;
    while (off > 0)
        drawcircle(c, off--, 0x3c35f9, w);
}

void        draw_all_curs(t_env *env, t_window *w)
{
    draw_red_curs(env, w);
    draw_green_curs(env, w);
    draw_blue_curs(env, w);
}
