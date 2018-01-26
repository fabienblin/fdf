/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   destructors.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/25 20:26:00 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 14:17:11 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_delsegment(t_seg *seg)
{
	free(seg);
	seg = NULL;
}

void	ft_delpoint(t_point *p)
{
	free(p);
	p = NULL;
}

void	ft_delenv(t_env *env)
{
	int i;
	int j;

	i = 0;
	while (i < env->len_y)
	{
		j = 0;
		while (j < env->len_x)
		{
			ft_delpoint(env->fdf[i][j]);
			j++;
		}
		i++;
	}
	free(env->mlx);
	free(env->win);
	free(env);
	env = NULL;
}

void	ft_delsplit(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}
