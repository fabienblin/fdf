/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 16:16:21 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 12:10:36 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	set_more_env(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->len_y)
	{
		j = 0;
		while (j < env->len_x)
		{
			env->fdf[i][j]->proj_y += (env->len_x - env->fdf[i][j]->x - 1)
				* ZOOM + BORDER;
			env->fdf[i][j]->proj_y /= 2;
			j++;
		}
		i++;
	}
	env->min_x = env->fdf[0][0]->proj_x;
	env->max_x = env->fdf[env->len_y - 1][env->len_x - 1]->proj_x;
	env->min_y = env->fdf[0][env->len_x - 1]->proj_y;
	env->max_y = env->fdf[env->len_y - 1][0]->proj_y;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx,
		env->max_x - env->min_x + 1 + 2 * BORDER,
		env->max_y - env->min_y + 1 + 2 * BORDER,
		"fdf");
}
