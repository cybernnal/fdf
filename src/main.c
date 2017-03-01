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

static void    init_env(t_env *env)
{
    env->max = -2147483648;
    env->min = 2147483647;
    env->rot = 0.523599;
    env->mrot = 0.01;
    env->rad =  2.0944;
    env->mrad = 0.01;
    env->cz = (float)-0.05;
    env->rzoom = 0.2;
}

static void    init_env_step2(t_env *env)
{
    env->xmax = env->mod;
    env->ymax = env->line;
    if (env->xmax > env->ymax)
        env->ratio = L_CF(1, 0, sqrt(env->xmax * env->xmax + env->ymax * env->ymax) * 1.5, 0, WIN_X);
    else
        env->ratio = L_CF(1, 0, sqrt(env->xmax * env->xmax + env->ymax * env->ymax) * 1.5, 0, WIN_Y);
    env->winx = env->xmax;//(int) (WIN_X - ((sqrt(env->xmax * env->xmax + env->ymax * env->ymax) * env->ratio) / 2));//env->xmax - env->xmax / 3;
}

int		main(int argc, char  **argv)
{
	t_env	env;

	if (argc < 1)
		ft_error("too few args");
    ft_bzero(&env, sizeof(t_env));
	init_env(&env);
    pars_map(&env, argv[1]);
    init_env_step2(&env);
    printf("r: %f, xm :%d ym: %d\n", env.ratio, env.xmax, env.ymax);
    while (render(&env));
	return (0);
}
