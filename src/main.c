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
}

static void    init_env_step2(t_env *env)
{
    env->xmax = env->mod;
    env->xmin = 0;
    env->ymax = env->line;
    env->ymin = 0;
}

int		main(int argc, char  **argv)
{
	t_env	env;
    int i;

    i = 0;
	if (argc < 1)
		ft_error("too few args");
    ft_bzero(&env, sizeof(t_env));
	init_env(&env);
    pars_map(&env, argv[1]);
    init_env_step2(&env);
    while (render(&env));
	return (0);
}
