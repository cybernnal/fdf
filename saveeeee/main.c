/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 13:46:15 by tbillard          #+#    #+#             */
/*   Updated: 2016/06/19 20:28:40 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void    init_env(t_env *env)
{
    ft_bzero(env, sizeof(t_env));
    env->max = -2147483648;
    env->min = 2147483647;
    env->rot = 0.523599;
    env->mrot = 0.01;
    env->rad =  2.0944;
    env->mrad = 0.01;
    env->cz = (float)-0.05;
    env->rzoom = 0.2;
    env->color.r1 = 0;
    env->color.r2 = 255;
    env->color.g1 = 255;
    env->color.g2 = 0;
    env->color.b1 = 255;
    env->color.b2 = 255;
}

void    init_env_step2(t_env *env)
{
    env->xmax = env->mod;
    env->ymax = env->line;
    if (env->xmax < env->ymax)
        env->ratio = L_CF(1, 0, env->xmax, 0, WIN_X);
    else
        env->ratio = L_CF(1, 0, env->ymax, 0, WIN_Y);
}

int		main(int argc, char  **argv)
{
	t_env	env;

	if (argc < 1)
		ft_error("too few args");
    init_env(&env);
    pars_map(&env, argv[1]);
    init_env_step2(&env);

    env.w = ft_memalloc(sizeof(t_img));

    init_window(env.w);
    printf("r: %f, xm :%d ym: %d\n\n", env.ratio, env.xmax, env.ymax);

    mlx_expose_hook(env.w->win, render, &env);
    //mlx_key_hook(env.w->win, key_hook, &env);
    mlx_hook(env.w->win, 2, (1L << 01), key_hook, &env);
//    mlx_loop_hook(env.w->win, render, &env);
    mlx_loop(env.w->mlx);
  	return (0);
}
