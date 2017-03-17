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
            env->col = (env->col + 1) % 4;
        if (event.key.keysym.sym == SDLK_w)
            env->cz += 0.05;
        if (event.key.keysym.sym == SDLK_e)
            env->cz -= 0.05;
        if (event.key.keysym.sym == SDLK_d)
            env->t = !env->t;
        if (event.key.keysym.sym == SDLK_c)
            env->config = !env->config;
        if (event.key.keysym.sym == SDLK_t)
            env->matrix = !env->matrix;

        int n = 5;
        
        if (event.key.keysym.sym == SDLK_1 && env->color.r1 - n >= 0)
            env->color.r1 -= n;
        if (event.key.keysym.sym == SDLK_2 && env->color.r1 + n <= 255)
            env->color.r1 += n;
        if (event.key.keysym.sym == SDLK_3 && env->color.r2 - n >= 0)
            env->color.r2 -= n;
        if (event.key.keysym.sym == SDLK_4 && env->color.r2 + n <= 255)
            env->color.r2 += n;
       
        if (event.key.keysym.sym == SDLK_5 && env->color.g1 - n >= 0)
            env->color.g1 -= n;
        if (event.key.keysym.sym == SDLK_6 && env->color.g1 + n <= 255)
            env->color.g1 += n;
        if (event.key.keysym.sym == SDLK_7 && env->color.g2 - n >= 0)
            env->color.g2 -= n;
        if (event.key.keysym.sym == SDLK_8 && env->color.g2 + n <= 255)
            env->color.g2 += n;
       
        if (event.key.keysym.sym == SDLK_9 && env->color.b1 - n >= 0)
            env->color.b1 -= n;
        if (event.key.keysym.sym == SDLK_0 && env->color.b1 + n <= 255)
            env->color.b1 += n;
        if (event.key.keysym.sym == '-' && env->color.b2 - n >= 0)
            env->color.b2 -= n;
        if (event.key.keysym.sym == '=' && env->color.b2 + n <= 255)
            env->color.b2 += n;
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

    if (e->up <= 0)
        z = (int)(e->min - e->up);
    else
        z = (int)(e->up + abs((int)e->min));
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

static Uint32       custom_color(t_env *env)
{
    int r;
    int g;
    int b;
 
    r = L_C(env->tab[env->y][env->x], env->min, env->max, env->color.r1, env->color.r2);
    g = L_C(env->tab[env->y][env->x], env->min, env->max, env->color.g1, env->color.g2);
    b = L_C(env->tab[env->y][env->x], env->min, env->max, env->color.b1, env->color.b2);
    return ((Uint32)((r << 16) + (g << 8) + b));
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
    if (e->up >= -10)
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
    return (ign_color_normeh(z2, e));
}

static void		ft_tab_ft_init(Uint32 (**tab_ft)(t_env *))
{
    tab_ft[0] = &ign_color;
    tab_ft[1] = &terra_color;
    tab_ft[2] = &map_color;
    tab_ft[3] = &custom_color;
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

static void      matrix2(t_trace *t, t_env *env)
{
    t->u = env->x;
    t->v = env->y;
    t->u1 = env->x + 1;
    t->u2 = env->x;
    t->v1 = env->y;
    t->v2 = env->y + 1;
}

static void		ft_matrix_ft_init(void (**tab_ft)(t_trace *, t_env *))
{
    tab_ft[1] = &matrix;
    tab_ft[0] = &matrix2;
}

static void		render_map(t_window *w, t_env *env)
{
    t_trace     t;
    static void    (*t_matrix[4])(t_trace *, t_env *) = {NULL};

    if (!t_matrix[0])
        ft_matrix_ft_init(t_matrix);
    ft_bzero(&t, sizeof(t_trace));
    t.coef = env->ratio;
    t.rot = env->rot;
    if (env->anim == 1)
        env->rot += env->mrot;
    if (env->anim2 == 1)
        env->rad += env->mrad;
    env->y = 0;
    while (env->y < env->line - 1)// && ((v2 + env->winy + z2 * env->cz) * coef) < WIN_Y && ((v2 + env->winy + z2 * env->cz) * coef) < WIN_X)// && ((env->y + env->winy) * coef) + coef < WIN_Y)
    {
        env->x = 0;
        while (env->x < env->mod - 1)// && ((env->x + env->winx) * coef) + coef < WIN_X)
        {
            env->up = env->tab[env->y][env->x];
            t.z = (int) env->tab[env->y][env->x];
            t.zx1 = (int) env->tab[env->y][env->x + 1];
            t.zy1 = (int) env->tab[env->y + 1][env->x];
            t_matrix[env->matrix](&t, env);
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
        t_matrix[env->matrix](&t, env);
        line((int) ((t.u + env->winx) * t.coef),                      // => x1
             (int) ((t.v + env->winy + t.z * env->cz) * t.coef),         // => y1
             (int) ((t.u2 + env->winx) * t.coef),                 // => x2
             (int) (((t.v2 + env->winy + t.zy1 * env->cz) * t.coef)),    // => y2
             w, env);

        ++env->y;
    }
    env->x = 0;
    while (env->x < env->mod - 1)
    {
        env->up = env->tab[env->y][env->x];
        t.z = (int) env->tab[env->y][env->x];
        t.zx1 = (int) env->tab[env->y][env->x + 1];
        t_matrix[env->matrix](&t, env);
        line((int) ((t.u + env->winx) * t.coef),                      // => x1
             (int) ((t.v + env->winy + t.z * env->cz) * t.coef),         // => y1
             (int) (((t.u1 + env->winx) * t.coef)),               // => x2
             (int) ((t.v1 + env->winy + t.zx1 * env->cz) * t.coef),       // => y2
             w, env);
        ++env->x;
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
    int sx0 = 2;
    int sy0 = 15;
    int sx = sx0 / 2;
    int sy = sy0 / 2;
    while (sy > -(sy0 / 2))
    {
        while (sx > -(sy0 / 2))
        {
            draw_pixel((x + sx), (y + sy), 0x0000CC, w);
            --sx;
        }
        sx = sx0 / 2;
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
    draw_curs(x0 + marge / 2 + z, y0 + marge + (i / 2), w);
}

int        render(t_env * env)
{
	static t_window w;
	if (!w.is_init)
	{
		init_window(&w);
		w.is_init = 1;
    }

    bzero(w.img_ptr, sizeof(Uint32) * WIN_Y * WIN_X);
    while (SDL_PollEvent(&w.event))
        key_handler(w.event, env);
    render_map(&w, env);
    if (env->config)
        render_conf(&w, env);
    SDL_UpdateTexture(w.image, NULL, w.img_ptr, WIN_X * sizeof(Uint32));
	SDL_RenderCopy(w.renderer, w.image, NULL, NULL);
	SDL_RenderPresent(w.renderer);
    return (1);
}
