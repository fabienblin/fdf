/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/18 01:32:45 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 12:44:17 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_HEIGHT 900
# define WIN_LENGHT 1600
# define BORDER 100
# define BASE_COLOR 0xFFFFFF
# define ZOOM 20

# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	proj_x;
	int	proj_y;
}				t_point;

typedef struct	s_segment
{
	t_point *a;
	t_point *b;
	int		dx;
	int		dy;
	int		xinc;
	int		yinc;
}				t_seg;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_point	***fdf;
	int		len_x;
	int		len_y;
	int		len_z;
	int		max_x;
	int		min_x;
	int		max_y;
	int		min_y;
	int		win_height;
	int		win_length;
}				t_env;

void			ft_delsegment(t_seg *seg);
void			ft_delpoint(t_point *p);
void			ft_delenv(t_env *env);
void			ft_delsplit(char **split);
t_point			*ft_newpoint(int x, int y, int z);
t_env			*ft_newenv();
t_seg			*ft_newsegment(t_point *a, t_point *b);
void			set_more_env(t_env *env);
int				ft_get_check_input(char *filename, t_env *env);
void			ft_putimage(t_env *env);
t_env			*ft_setenv(t_env *env, char **argv);
void			set_more_env(t_env *env);
#endif
