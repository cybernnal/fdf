/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 19:48:27 by tbillard          #+#    #+#             */
/*   Updated: 2016/06/19 20:15:21 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int nb_nb(char *str)
{
    int i;
    int nb;

    nb = 0;
    i = 0;
    while (str[i])
    {
        while (str[i] && str[i] != '\n' && str[i] != ' ')
        {
            i++;
        }
        if (i != 0)
            nb++;
        while (str[i] && (str[i] == '\n' || str[i] == ' '))
        {
            i++;
        }
    }
    return (nb);
}

static void     put_nb(t_env *env, t_fdf nb, int i)
{
    env->tab[i] = nb;
    if (env->min > nb)
        env->min = nb;
    if (env->max < nb)
        env->max = nb;
}

int			c_to_d(t_env *env)
{
	int		i;
	int		j;
    int     m;
	char	**tb;

    m = 0;
    i = 0;
	j = 0;
    env->mod = nb_nb(env->map[0]);
	env->tab = (t_fdf*)ft_memalloc(sizeof(t_fdf) * (env->line * env->mod));
	while (env->map[m])
	{
		tb = ft_strsplit(env->map[m], ' ');
        m++;
		while (tb[j])
		{
			put_nb(env, ft_atoidbl(tb[j]), i);
			i++;
			j++;
		}
		ft_freetab(&tb);
        if (j != env->mod)
			ft_error("map error");
        j = 0;
	}
    return (1);
}
