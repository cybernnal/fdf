#include "panel.h"

static void     draw_black(t_window *w)
{
    int x;
    int y;

    x = CONF_X0;
    y = 0;
    while (y < CONF_YM)
    {
        while (x < WIN_X)
            draw_pixel(x++, y, 0, w);
        x = CONF_X0;
        y++;
    }
}

void render_conf(t_window *w, t_env *env)
{
    draw_black(w);
    draw_all_slide(w, env);
    mouse_hit(env);
    draw_all_curs(env, w);
}