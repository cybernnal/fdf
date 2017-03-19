/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_rot_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:23:13 by tbillard          #+#    #+#             */
/*   Updated: 2017/03/18 16:23:25 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ro_i(t_env *env)
{
	env->rot += env->mrot;
	return (0);
}

int		ro_d(t_env *env)
{
	env->rot -= env->mrot;
	return (0);
}

int		rov_i(t_env *env)
{
	env->mrot += 0.01;
	return (0);
}

int		rov_d(t_env *env)
{
	env->mrot -= 0.01;
	return (0);
}
