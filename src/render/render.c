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

static void			render_loop(t_trace t, t_env *env, t_img *w,
		void (**t_matrix)(t_trace *, t_env *))
{
	while (++env->y < env->line - 1 && (env->x = -1))
	{
		while (++env->x < env->mod - 1)
		{
			env->up = env->tab[env->y][env->x];
			t.z = (int)env->tab[env->y][env->x];
			t.zx1 = (int)env->tab[env->y][env->x + 1];
			t.zy1 = (int)env->tab[env->y + 1][env->x];
			t_matrix[env->matrix](&t, env);
			call_line(t, env, w, 0);
		}
		t.z = (int)env->tab[env->y][env->x];
		t.zy1 = (int)env->tab[env->y + 1][env->x];
		t_matrix[env->matrix](&t, env);
		call_line(t, env, w, 2);
	}
	env->x = -1;
	while (++env->x < env->mod - 1)
	{
		env->up = env->tab[env->y][env->x];
		t.z = (int)env->tab[env->y][env->x];
		t.zx1 = (int)env->tab[env->y][env->x + 1];
		t_matrix[env->matrix](&t, env);
		call_line(t, env, w, 1);
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
	env->y = -1;
	render_loop(t, env, w, t_matrix);
}

int					render(t_env *env)
{
	ft_bzero(env->w->buf, WIN_Y * WIN_X * 4);
	render_map(env->w, env);
	mlx_put_image_to_window(env->w->mlx, env->w->win, env->w->data, 0, 0);
	return (1);
}
