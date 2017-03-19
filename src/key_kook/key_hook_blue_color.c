/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_blue_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:13:06 by tbillard          #+#    #+#             */
/*   Updated: 2017/03/18 16:13:30 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		bo_m(t_env *env)
{
	if (env->color.b1 - NB > 0)
		env->color.b1 -= NB;
	else
		env->color.b1 = 0;
	return (0);
}

int		bo_p(t_env *env)
{
	if (env->color.b1 + NB < 255)
		env->color.b1 += NB;
	else
		env->color.b1 = 255;
	return (0);
}

int		bt_m(t_env *env)
{
	if (env->color.b2 - NB > 0)
		env->color.b2 -= NB;
	else
		env->color.b2 = 0;
	return (0);
}

int		bt_p(t_env *env)
{
	if (env->color.b2 + NB < 255)
		env->color.b2 += NB;
	else
		env->color.b2 = 255;
	return (0);
}
