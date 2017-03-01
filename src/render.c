#include <time.h>
#include "fdf.h"

static void key_handler(SDL_Event event, t_env *env)
{
	if (event.type == SDL_KEYDOWN)
	{
         int nb = (env->ratio > 10 ? 1 : 50);

        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            printf("ratio final : %f, wx: %d, wy: %d \n", env->ratio, env->winx, env->winy);
            exit(EXIT_SUCCESS);
        }
        if (event.key.keysym.sym == SDLK_x)
            env->rzoom += 0.1;
        if (event.key.keysym.sym == SDLK_s)
            if (env->rzoom - 0.1 > 0)
                env->rzoom -= 0.1;
        if (event.key.keysym.sym == SDLK_z)
            env->ratio += env->rzoom;
        if (event.key.keysym.sym == SDLK_a)
          if (env->ratio - env->rzoom > 0)
                env->ratio -= env->rzoom;
        if (event.key.keysym.sym == SDLK_LEFT)
            env->winx += nb;
        if (event.key.keysym.sym == SDLK_RIGHT)
            env->winx -= nb;
        if (event.key.keysym.sym == SDLK_DOWN)
            env->winy -= nb;
        if (event.key.keysym.sym == SDLK_UP)
            env->winy += nb;
        if (event.key.keysym.sym == SDLK_n)
            env->rot -= env->mrot;
        if (event.key.keysym.sym == SDLK_m)
            env->rot += env->mrot;
        if (event.key.keysym.sym == SDLK_j)
            env->mrot -= 0.01;
        if (event.key.keysym.sym == SDLK_k)
            env->mrot += 0.01;
        if (event.key.keysym.sym == SDLK_p)
            env->anim = !env->anim;
        if (event.key.keysym.sym == SDLK_v)
            env->rad -= env->mrad;
        if (event.key.keysym.sym == SDLK_b)
            env->rad += env->mrad;
        if (event.key.keysym.sym == SDLK_g)
            env->mrad -= 0.01;
        if (event.key.keysym.sym == SDLK_h)
            env->mrad += 0.01;
        if (event.key.keysym.sym == SDLK_o)
            env->anim2 = !env->anim2;
        if (event.key.keysym.sym == SDLK_q)
            env->col = (env->col + 1) % 3;
        if (event.key.keysym.sym == SDLK_w)
            env->cz += 0.05;
        if (event.key.keysym.sym == SDLK_e)
            env->cz -= 0.05;
        if (event.key.keysym.sym == SDLK_d)
            env->t = !env->t;
        if (event.key.keysym.sym == SDLK_c)
            env->config = !env->config;
    }
}

static void draw_pixel(int x, int y, Uint32 color, t_window *w)
{
    if ((y > WIN_Y || x > WIN_X || x < 0 || y < 0))
    {
       //ft_putendl("pixel over/under flow");
        return ;
    }
        w->img_ptr[WIN_X * y + x] = color;
//    SDL_UpdateTexture(w->image, NULL, w->img_ptr, WIN_X * sizeof(Uint32));
//    SDL_RenderCopy(w->renderer, w->image, NULL, NULL);
//    SDL_RenderPresent(w->renderer);
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

static Uint32       map_color(t_env *env)
{
    Uint32 min;
    Uint32 max;

    min = 0x000000;
    max =  0xffffff;
    return ((Uint32)L_C(env->tab[env->y][env->x], env->min, env->max, min, max));
}

static Uint32       arc_color(int interval) {
    int value = 1530;
    Uint32 color;
    int x = (1530 / interval) * value;
    int r;
    int g;
    int b;

    if (x >= 0 && x < 255){
        r = 255;
        g = x;
        b = 0;
    }
    if (x >= 255 && x < 510){
        r = 510 - x;
        g = 255;
        b = 0;
    }
    if (x >= 510 && x < 765){
        r = 0;
        g = 255;
        b = x - 510;
    }
    if (x >= 765 && x < 1020){
        r = 0;
        g = 1020 - x;
        b = 255;
    }
    if (x >= 1020 && x < 1275){
        r = x - 1020;
        g = 0;
        b = 255;
    }
    if (x >= 1275 && x < 1530){
        r = 255;
        g = 0;
        b = 1530 - x;
    }
    color = (Uint32) (r << 16, g << 8, b);
    return (color);
}

static Uint32       map_color2(t_env *env, int i)
{
    Uint32 min;
    Uint32 max;

    min = 0x000000;
    max =  0xffffff;
    return ((Uint32)L_C(env->tab[env->y][env->x] + i, env->min, env->max + 500, min, max));
}

static Uint32	ign_color_normeh(int z2, t_env *e)
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
    if (e->down >= -10 || e->up >= -10)
        return (0xd8f2fe);
    if (z2 > -50)
        return (0xb9e3ff);
    if (z2 > -75)
        return (0x96c9f0);
    else
        return (0x71abd8);
}

static Uint32	ign_color(t_env *e)
{
    int				z2;

    z2 = (int)e->down;
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
    return (ign_color_normeh(z2, e));
}

static void		ft_tab_ft_init(Uint32 (**tab_ft)(t_env *))
{
    tab_ft[0] = &ign_color;
    tab_ft[1] = &terra_color;
    tab_ft[2] = &map_color;
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
    static Uint32    (*t_color[3])(t_env *) = {NULL};

    if (!t_color[0])
        ft_tab_ft_init(t_color);
    if (e->config && ((x1 > CONF_X0 && y1 < CONF_YM) || (x0 > CONF_X0 && y1 < CONF_YM)))
        return;
    if (e->t && (y0 > WIN_Y || x0 > WIN_X || x0 < 0 || y0 < 0 || y1 > WIN_Y || x1 > WIN_X || x1 < 0 || y1 < 0))
    {
    //   ft_putendl("pixel over/under flow");
        return ;
    }
    color = t_color[e->col](e);
    dx = abs(x1-x0);
    sx = x0 < x1 ? 1 : -1;
    dy = abs(y1-y0);
    sy = y0 <y1 ? 1 : -1;
    err = (dx > dy ? dx : -dy) / 2;
    int i = 0;//////////////////////////
    while (1)
    {
        i++;/////////////////////
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

static float mem_co(float t)
{
    static float lookup[16384];
    int          i = (int)(t * 100);

    if (i >= 16384 || i < 0)
        return (cosf(t));
    if (lookup[i])
        return (lookup[i]);
    else
    {
        lookup[i] = cosf(t);
        return (lookup[i]);
    }
}

static float mem_si(float t)
{
    static float lookup[16384];
    int          i = (int)(t * 100);

    if (i >= 16384 || i < 0)
        return (sinf(t));
    if (lookup[i])
        return (lookup[i]);
    else
    {
        lookup[i] = sinf(t);
        return (lookup[i]);
    }
}

static void      matrix(t_trace *t, t_env *env)
{
    t->u = env->x * mem_co(t->rot) + env->y * mem_co((float) (t->rot + env->rad));
    t->v = env->x * mem_si(t->rot) + env->y * mem_si((float) (t->rot + env->rad));
    t->u1 = (env->x + 1) * mem_co(t->rot) + env->y * mem_co((float) (t->rot + env->rad));
    t->v1 = (env->x + 1) * mem_si(t->rot) + env->y * mem_si((float) (t->rot + env->rad));
    t->u2 = env->x * mem_co(t->rot) + (env->y + 1) * mem_co((float) (t->rot + env->rad));
    t->v2 = env->x * mem_si(t->rot) + (env->y + 1) * mem_si((float) (t->rot + env->rad));
}

static void		render_map(t_window *w, t_env *env)
{
    t_trace     t;
    
    ft_bzero(&t, sizeof(t_trace));
    t.coef = env->ratio;
    t.rot = env->rot;
    if (env->anim == 1)
        env->rot += env->mrot;
    if (env->anim2 == 1)
        env->rad += env->mrad;
    env->y = 0;//y1;
    
    while (env->y < env->line - 1)// && ((v2 + env->winy + z2 * env->cz) * coef) < WIN_Y && ((v2 + env->winy + z2 * env->cz) * coef) < WIN_X)// && ((env->y + env->winy) * coef) + coef < WIN_Y)
    {
        env->x = 0;//x1;
        while (env->x < env->mod - 1)// && ((env->x + env->winx) * coef) + coef < WIN_X)
        {
            if (env->y > 0 || env->x > 0)
                env->up = env->tab[env->y][env->x];
            env->down = env->tab[env->y][env->x];

            t.z = (int) env->tab[env->y][env->x];
            t.zx1 = (int) env->tab[env->y][env->x + 1];
            t.zy1 = (int) env->tab[env->y + 1][env->x];
            matrix(&t, env);//&t!!!
            line((int) ((t.u + env->winx) * t.coef),                      // => x1
                 (int) ((t.v + env->winy + t.z * env->cz) * t.coef),         // => y1
                 (int) (((t.u1 + env->winx) * t.coef)),               // => x2
                 (int) ((t.v1 + env->winy + t.zx1 * env->cz) * t.coef),       // => y2
                 w, env);

            line((int) ((t.u + env->winx) * t.coef),                      // => x1
                 (int) ((t.v + env->winy + t.z * env->cz) * t.coef),         // => y1
                 (int) ((t.u2 + env->winx) * t.coef),                 // => x2
                 (int) (((t.v2 + env->winy + t.zy1 * env->cz) * t.coef)),    // => y2
                 w, env);
                ++env->x;
        }
        t.z = (int) env->tab[env->y][env->x];
        t.zy1 = (int) env->tab[env->y + 1][env->x];

        matrix(&t, env);
        line((int) ((t.u + env->winx) * t.coef),                      // => x1
             (int) ((t.v + env->winy + t.z * env->cz) * t.coef),         // => y1
             (int) ((t.u2 + env->winx) * t.coef),                 // => x2
             (int) (((t.v2 + env->winy + t.zy1 * env->cz) * t.coef)),    // => y2
             w, env);

        ++env->y;
    }
  }

static void line2(int x0, int y0, int x1, int y1, t_window *w)
{

    int dx;
    int sx;
    int dy;
    int sy;
    int err;
    int e2;
    Uint32 color;

    if ((y0 > WIN_Y || x0 > WIN_X || x0 < 0 || y0 < 0 || y1 > WIN_Y || x1 > WIN_X || x1 < 0 || y1 < 0))
    {
        ft_putendl("pixel over/under flow on config window");
        return ;
    }
    color = 0xc3a76b;
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

static void draw_curs(int x, int y, t_window *w)
{
    int sx0 = 6;
    int sy0 = 30;
    int sx = sx0;
    int sy = sy0;
    while (sy > 0)
    {
        while (sx > 0)
        {
            draw_pixel((x + sx) - sx0 / 2, (y + sy) - sy / 2, 0x0000CC, w);
            --sx;
        }
        sx = sx0;
        --sy;
    }
}

static void render_conf(t_window *w, t_env *env)
{
    int x0 = CONF_X0;
    int y0 = 0;
    int marge = 30;
    static int z = 120;
    int i = 0;

    while (i < 4)
    {
        line2(x0 + marge / 2, y0 + marge + i, (x0 + marge / 2) + 240, y0 + marge + i, w);
        i++;
    }
    draw_curs(x0 + marge / 2 + z, y0 + marge + i, w);
}

int        render(t_env * env)
{
	static t_window w;
//    static t_window w2;

	if (!w.is_init)
	{
		init_window(&w);
		w.is_init = 1;
//        init_window2(&w2);
//        w2.is_init = 1;
    }

    bzero(w.img_ptr, sizeof(Uint32) * WIN_Y * WIN_X);

//    bzero(w2.img_ptr, sizeof(Uint32) * CONF_X * CONF_Y);

    while (SDL_PollEvent(&w.event))
        key_handler(w.event, env);


    render_map(&w, env);
    if (env->config)
        render_conf(&w, env);

//    render_conf(&w2, env);

    SDL_UpdateTexture(w.image, NULL, w.img_ptr, WIN_X * sizeof(Uint32));
	SDL_RenderCopy(w.renderer, w.image, NULL, NULL);
	SDL_RenderPresent(w.renderer);

//    SDL_UpdateTexture(w2.image, NULL, w2.img_ptr, CONF_X * sizeof(Uint32));
//    SDL_RenderCopy(w2.renderer, w2.image, NULL, NULL);
//    SDL_RenderPresent(w2.renderer);
    return (1);
}
