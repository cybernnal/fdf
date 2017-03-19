#include "panel.h"

static void     draw_red_slide(t_window *w, t_env *env)
{
    t_line l;
    int i;

    i = 0;
    l.x0 = CONF_X0 + MARGE / 2;
    l.x1 = l.x0 + SIZE;
    while (i < 4)
    {
        l.y0 = MARGE + i;
        l.y1 = l.y0;
        l2(l, env, w, 0);
        i++;
    }
}

static void     draw_green_slide(t_window *w, t_env *env)
{
    t_line l;
    int i;

    i = 0;
    l.x0 = CONF_X0 + MARGE / 2;
    l.x1 = l.x0 + SIZE;
    while (i < 4)
    {
        l.y0 = MARGE + i + BT;
        l.y1 = l.y0;
        l2(l, env, w, 1);
        i++;
    }
}

static void     draw_blue_slide(t_window *w, t_env *env)
{
    t_line l;
    int i;

    i = 0;
    l.x0 = CONF_X0 + MARGE / 2;
    l.x1 = l.x0 + SIZE;
    while (i < 4)
    {
        l.y0 = MARGE + i + BT * 2;
        l.y1 = l.y0;
        l2(l, env, w, 2);
        i++;
    }
}

void     draw_all_slide(t_window *w, t_env *e)
{
    draw_red_slide(w, e);
    draw_green_slide(w, e);
    draw_blue_slide(w, e);
}