/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_red_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:14:27 by tbillard          #+#    #+#             */
/*   Updated: 2017/03/18 16:15:47 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ro_m(t_env *env)
{
	if (env->color.r1 - NB > 0)
		env->color.r1 -= NB;
	else
		env->color.r1 = 0;
	return (0);
}

int		ro_p(t_env *env)
{
	if (env->color.r1 + NB < 255)
		env->color.r1 += NB;
	else
		env->color.r1 = 255;
	return (0);
}

int		rt_m(t_env *env)
{
	if (env->color.r2 - NB > 0)
		env->color.r2 -= NB;
	else
		env->color.r2 = 0;
	return (0);
}

int		rt_p(t_env *env)
{
	if (env->color.r2 + NB < 255)
		env->color.r2 += NB;
	else
		env->color.r2 = 255;
	return (0);
}
