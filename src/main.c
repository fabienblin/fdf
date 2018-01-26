/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 11:32:36 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 20:39:38 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		ft_escape_key(int key, void *env)
{
	if (key == 53)
	{
		ft_delenv(env);
		exit(0);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 2)
	{
		env = ft_newenv();
		ft_setenv(env, argv);
		set_more_env(env);
		ft_putimage(env);
		mlx_key_hook(env->win, ft_escape_key, env);
		mlx_loop(env->mlx);
	}
	else
		ft_exit("Usage : ./fdf <filename>");
	return (0);
}
