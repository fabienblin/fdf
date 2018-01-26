/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   constructors.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 13:15:20 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 14:12:33 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_point	*ft_newpoint(int x, int y, int z)
{
	t_point *p;

	if (!(p = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	p->x = x;
	p->y = y;
	p->z = z;
	p->proj_x = (p->x * ZOOM) + (p->y * ZOOM) + BORDER;
	p->proj_y = (p->y * ZOOM) - (p->z * ZOOM / 3) + BORDER;
	return (p);
}

t_env	*ft_newenv(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	ft_bzero(env, sizeof(t_env));
	env->len_x = 0;
	env->len_y = 0;
	env->len_z = 0;
	return (env);
}

t_seg	*ft_newsegment(t_point *a, t_point *b)
{
	t_seg	*seg;

	if (!(seg = (t_seg *)malloc(sizeof(t_seg))))
		return (NULL);
	ft_bzero(seg, sizeof(t_seg));
	if (a && b)
	{
		seg->a = a;
		seg->b = b;
		seg->dx = b->proj_x - a->proj_x;
		seg->dy = b->proj_y - a->proj_y;
		seg->xinc = (seg->dx > 0 ? 1 : -1);
		seg->yinc = (seg->dy > 0 ? 1 : -1);
		seg->dx = abs(seg->dx);
		seg->dy = abs(seg->dy);
	}
	return (seg);
}
