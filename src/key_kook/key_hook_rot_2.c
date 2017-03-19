/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_rot_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:23:40 by tbillard          #+#    #+#             */
/*   Updated: 2017/03/18 16:23:56 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		rt_i(t_env *env)
{
	env->rad += env->mrad;
	return (0);
}

int		rt_d(t_env *env)
{
	env->rad -= env->mrad;
	return (0);
}

int		rtv_i(t_env *env)
{
	env->mrad += 0.01;
	return (0);
}

int		rtv_d(t_env *env)
{
	env->mrad -= 0.01;
	return (0);
}
