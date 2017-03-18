/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:21:58 by tbillard          #+#    #+#             */
/*   Updated: 2017/03/18 16:22:51 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		matrix_hook(t_env *env)
{
	env->matrix = !env->matrix;
	return (0);
}

int		ft_exit(t_env *env)
{
	ft_end(env);
	return (0);
}

int		c_color(t_env *env)
{
	env->col = (env->col + 1) % 4;
	return (0);
}

int		opti(t_env *env)
{
	env->t = !env->t;
	return (0);
}

int		nil(t_env *env)
{
	return (0);
}
