/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:50:22 by tbillard          #+#    #+#             */
/*   Updated: 2017/03/18 18:50:23 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				draw_pixel(char *buf, int x, int y, int color)
{
	if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
	{
		x *= 4;
		y *= 4;
		buf[(x++) + (y * WIN_X)] = (char)(color << 24 >> 24);
		buf[(x++) + (y * WIN_X)] = (char)(color << 16 >> 16);
		buf[(x) + (y * WIN_X)] = (char)(color >> 16);
	}
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

static Uint32		map_color(t_env *env)
{
	Uint32 min;
	Uint32 max;

	min = 0x000000;
	max = 0xffffff;
	return ((Uint32)L_C(env->tab[env->y][env->x],
				env->min, env->max, min, max));
}

static Uint32		custom_color(t_env *env)
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

static Uint32		ign_color_normeh(int z2, t_env *e)
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

static Uint32		ign_color(t_env *e)
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

static void			ft_tab_ft_init(Uint32 (**tab_ft)(t_env *))
{
	tab_ft[0] = &ign_color;
	tab_ft[1] = &terra_color;
	tab_ft[2] = &map_color;
	tab_ft[3] = &custom_color;
}

static void			loop_line(t_line l, t_env *e,
		Uint32 (**t_color)(t_env *))
{
	l.color = t_color[e->col](e);
	l.dx = abs(l.x1 - l.x0);
	l.sx = l.x0 < l.x1 ? 1 : -1;
	l.dy = abs(l.y1 - l.y0);
	l.sy = l.y0 < l.y1 ? 1 : -1;
	l.err = (l.dx > l.dy ? l.dx : -l.dy) / 2;
	while (1)
	{
		draw_pixel(e->w->buf, l.x0, l.y0, (int)l.color);
		if (l.x0 == l.x1 && l.y0 == l.y1)
			break ;
		l.e2 = l.err;
		if (l.e2 > -l.dx)
		{
			l.err -= l.dy;
			l.x0 += l.sx;
		}
		if (l.e2 < l.dy)
		{
			l.err += l.dx;
			l.y0 += l.sy;
		}
	}
}

static void			line(t_line l, t_env *e)
{
	static Uint32	(*t_color[3])(t_env *) = {NULL};

	if (!t_color[0])
		ft_tab_ft_init(t_color);
	if (e->config && ((l.x1 > CONF_X0 && l.y1 < CONF_YM)
				|| (l.x0 > CONF_X0 && l.y1
					< CONF_YM)))
		return ;
	if (e->t && (l.y0 > WIN_Y || l.x0 > WIN_X || l.x0 < 0
				|| l.y0 < 0 || l.y1 > WIN_Y ||
				l.x1 > WIN_X || l.x1 < 0 || l.y1 < 0))
		return ;
	loop_line(l, e, t_color);
}

static void			matrix(t_trace *t, t_env *env)
{
	t->u = env->x * cosf(t->rot) + env->y * cosf((t->rot + env->rad));
	t->v = env->x * sinf(t->rot) + env->y * sinf((t->rot + env->rad));
	t->u1 = (env->x + 1) * cosf(t->rot) + env->y * cosf((t->rot + env->rad));
	t->v1 = (env->x + 1) * sinf(t->rot) + env->y * sinf((t->rot + env->rad));
	t->u2 = env->x * cosf(t->rot) + (env->y + 1) * cosf((t->rot + env->rad));
	t->v2 = env->x * sinf(t->rot) + (env->y + 1) * sinf((t->rot + env->rad));
}

static void			matrix2(t_trace *t, t_env *env)
{
	t->u = env->x;
	t->v = env->y;
	t->u1 = env->x + 1;
	t->u2 = env->x;
	t->v1 = env->y;
	t->v2 = env->y + 1;
}

static void			ft_matrix_ft_init(void (**tab_ft)(t_trace *, t_env *))
{
	tab_ft[1] = &matrix;
	tab_ft[0] = &matrix2;
}

static void			call_line(t_trace t, t_env *env, t_img *w, int nb)
{
	t_line		l;

	l.x0 = (int)((t.u + env->winx) * t.coef);
	l.y0 = (int)((t.v + env->winy + t.z * env->cz) * t.coef);
	if (nb == 0 || nb == 1)
	{
		l.x1 = (int)(((t.u1 + env->winx) * t.coef));
		l.y1 = (int)((t.v1 + env->winy + t.zx1 * env->cz) * t.coef);
		line(l, env);
	}
	if (nb == 0 || nb == 2)
	{
		l.x1 = (int)((t.u2 + env->winx) * t.coef);
		l.y1 = (int)(((t.v2 + env->winy + t.zy1 * env->cz) * t.coef));
		line(l, env);
	}
}

static void			render_loop(t_trace t, t_env *env, t_img *w,
		void (**t_matrix)(t_trace *, t_env *))
{
	while (env->y < env->line - 1)
	{
		env->x = 0;
		while (env->x < env->mod - 1)
		{
			env->up = env->tab[env->y][env->x];
			t.z = (int)env->tab[env->y][env->x];
			t.zx1 = (int)env->tab[env->y][env->x + 1];
			t.zy1 = (int)env->tab[env->y + 1][env->x];
			t_matrix[env->matrix](&t, env);
			call_line(t, env, w, 0);
			++env->x;
		}
		t.z = (int)env->tab[env->y][env->x];
		t.zy1 = (int)env->tab[env->y + 1][env->x];
		t_matrix[env->matrix](&t, env);
		call_line(t, env, w, 2);
		++env->y;
	}
}

static void			render_map(t_img *w, t_env *env)
{
	t_trace			t;
	static void		(*t_matrix[4])(t_trace *, t_env *) = {NULL};

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
	render_loop(t, env, w, t_matrix);
	env->x = 0;
	while (env->x < env->mod - 1)
	{
		env->up = env->tab[env->y][env->x];
		t.z = (int)env->tab[env->y][env->x];
		t.zx1 = (int)env->tab[env->y][env->x + 1];
		t_matrix[env->matrix](&t, env);
		call_line(t, env, w, 1);
		++env->x;
	}
}

int					render(t_env *env)
{
	ft_bzero(env->w->buf, WIN_Y * WIN_X * 4);
	render_map(env->w, env);
	mlx_put_image_to_window(env->w->mlx, env->w->win, env->w->data, 0, 0);
	return (1);
}
