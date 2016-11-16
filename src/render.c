#include <time.h>
#include "fdf.h"

static void key_handler(SDL_Event event, t_env *env)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_ESCAPE)
			exit(EXIT_SUCCESS);
        if (event.key.keysym.sym == SDLK_z)
            env->zoom += 12;
        if (event.key.keysym.sym == SDLK_a && env->zoom >= 12)
            env->zoom -= 12;
        if (event.key.keysym.sym == SDLK_LEFT && env->xmin >= 4)
        {
          //  env->xmin -= 4;
            env->xmax -= 4;
        }
        if (event.key.keysym.sym == SDLK_RIGHT && env->xmax <= env->mod - 4)
        {
           // env->xmin += 4;
            env->xmax += 4;
        }
        if (event.key.keysym.sym == SDLK_DOWN && env->ymax <= env->line - 4)
        {
            env->ymin += 4;
            env->ymax += 4;
        }
        if (event.key.keysym.sym == SDLK_UP && env->ymin >= 4)
        {
            env->ymin -= 4;
            env->ymax -= 4;
        }
    }
}

static void draw_pixel(int x, int y, Uint32 color, t_window *w)
{
	w->img_ptr[WIN_WIDTH * y + x] = color;
   // SDL_UpdateTexture(w->image, NULL, w->img_ptr, WIN_WIDTH * sizeof(Uint32));
   // SDL_RenderCopy(w->renderer, w->image, NULL, NULL);
   // SDL_RenderPresent(w->renderer);
}

static Uint32		terra_color(t_env *e)
{
    int				s;
    int				z;

    if (e->down <= 0 || e->up <= 0)
        z = (int)(e->min - e->down);
    else
        z = (int)(e->down + abs((int)e->min));
    z = z == 0 ? 1 : abs(z);
    s = (int)(abs((int)e->min) + e->max);
    return ((Uint32)((z * 255 / s) << 16) + ((z * 255 / s) << 8) + z * 255 / s);
}
# define L_C(X, x1, x2, y1, y2) (((int)((X - x1) * (y2 - y1)) / (x2 - x1)) + y1)

static Uint32       map_color(t_env *env)
{
    Uint32 min;
    Uint32 max;

    min = (0 << 16) + (127 << 8) +  255;
    max = (153 << 16) + (81 << 8) +  43;
    return ((Uint32)L_C(env->tab[env->i], env->min, env->max, min, max));
}

static void line(int x0, int y0, int x1, int y1, t_window *w, t_env *e)
{

	int dx;
    int sx;
	int dy;
    int sy;
	int err;
    int e2;
    Uint32 color;

    color = map_color(e);
    dx = abs(x1-x0);
    sx = x0 < x1 ? 1 : -1;
    dy = abs(y1-y0);
    sy = y0 <y1 ? 1 : -1;
    err = (dx > dy ? dx : -dy) / 2;
    while (1)
    {
		draw_pixel(x0, y0, color, w);
		if (x0 == x1 && y0 == y1)
            break;
		e2 = err;
		if (e2 > -dx)
        {
            err -= dy;
            x0 += sx;
        }
		if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
	}
}

static void     zoom(t_env *env)
{
    int     step;
    static int zoom = 0;

    if (zoom == 0)
        zoom = env->zoom;
    if (zoom != env->zoom)
    {
        step = env->zoom - zoom;
        env->ymin += step;
        env->ymax -= step;
        env->xmin += step * 1.5;// * 2 ;//L_C(step, 0, WIN_HEIGHT, 0, WIN_WIDTH);
        env->xmax -= step * 1.5;// * 2 ;//L_C(step, 0, WIN_HEIGHT, 0, WIN_WIDTH);
        zoom = env->zoom;
    }
}

static void		render_map(t_window *w, t_env *env)
{
    int m;

    m = 0;
    zoom(env);
	env->i = env->xmin + (env->ymin * env->mod);
    while (env->i < env->xmax * env->ymax)
	{
        env->down = env->tab[env->i];
        if (env->i > 0)
            env->up = env->tab[env->i - 1];
        if (env->i % env->mod != env->mod - 1)
            line(L_C(env->i % env->mod, env->xmin, env->xmax, m, WIN_WIDTH - m), L_C(env->i / env->mod, env->ymin, env->ymax, m, WIN_HEIGHT - m), L_C((env->i + 1) % env->mod, env->xmin, env->xmax, m, WIN_WIDTH - m), L_C((env->i + 1) / env->mod, env->ymin, env->ymax, m, WIN_HEIGHT - m), w, env);
        if (env->i + env->mod < env->line * env->mod)
            line(L_C(env->i % env->mod, env->xmin, env->xmax, m, WIN_WIDTH - m), L_C(env->i / env->mod, env->ymin, env->ymax, m, WIN_HEIGHT - m), L_C((env->i) % env->mod, env->xmin, env->xmax, m, WIN_WIDTH - m), L_C((env->i + env->mod) / env->mod, env->ymin, env->ymax, m, WIN_HEIGHT - m), w, env);
        ++env->i;
        if (env->i % env->mod >= env->xmax)
        {
            env->i += env->mod - (env->i % env->mod);
        }
        if (env->i % env->mod < env->xmin)
            env->i += env->xmin;
    }
}

int        render(t_env * env)
{
	static t_window w;

	if (!w.is_init)
	{
		init_window(&w);
		w.is_init = 1;
	}
    bzero(w.img_ptr, sizeof(Uint32) * WIN_HEIGHT * WIN_WIDTH);
	while (SDL_PollEvent(&w.event))
		key_handler(w.event, env);
	render_map(&w, env);
	SDL_UpdateTexture(w.image, NULL, w.img_ptr, WIN_WIDTH * sizeof(Uint32));
	SDL_RenderCopy(w.renderer, w.image, NULL, NULL);
	SDL_RenderPresent(w.renderer);
    return (1);
}
