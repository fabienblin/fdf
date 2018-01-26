/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   output.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 17:04:05 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 21:40:15 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	tracex(t_env *env, t_seg *seg)
{
	int x;
	int y;
	int cumul;
	int i;

	x = seg->a->proj_x;
	y = seg->a->proj_y;
	cumul = seg->dx / 2;
	i = 1;
	while (i <= seg->dx)
	{
		x += seg->xinc;
		cumul += seg->dy;
		if (cumul >= seg->dx)
		{
			cumul -= seg->dx;
			y += seg->yinc;
		}
		mlx_pixel_put(env->mlx, env->win, x, y, BASE_COLOR);
		i++;
	}
}

void	tracey(t_env *env, t_seg *seg)
{
	int x;
	int y;
	int cumul;
	int i;

	x = seg->a->proj_x;
	y = seg->a->proj_y;
	cumul = seg->dy / 2;
	i = 1;
	while (i <= seg->dy)
	{
		y += seg->yinc;
		cumul += seg->dx;
		if (cumul >= seg->dy)
		{
			cumul -= seg->dy;
			x += seg->xinc;
		}
		mlx_pixel_put(env->mlx, env->win, x, y, BASE_COLOR);
		i++;
	}
}

void	bresenham(t_env *env, t_point *a, t_point *b)
{
	t_seg	*seg;

	if (!(seg = ft_newsegment(a, b)))
		return ;
	mlx_pixel_put(env->mlx, env->win, a->proj_x, a->proj_y, BASE_COLOR);
	if (seg->dx > seg->dy)
		tracex(env, seg);
	else
		tracey(env, seg);
	ft_delsegment(seg);
}

void	ft_putimage(t_env *env)
{
	t_point	*a;
	t_point	*b;
	int		i;
	int		j;

	i = -1;
	while (++i < env->len_y)
	{
		j = -1;
		while (++j < env->len_x)
		{
			a = env->fdf[i][j];
			if (a->x < env->len_x - 1)
			{
				b = env->fdf[i][j + 1];
				bresenham(env, a, b);
			}
			if (a->y < env->len_y - 1)
			{
				b = env->fdf[i + 1][j];
				bresenham(env, a, b);
			}
		}
	}
}
