/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/18 19:10:03 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 14:16:19 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_split(char **split)
{
	int	count;

	count = 0;
	if (!split)
		return (0);
	while (split[count])
		count++;
	return (count);
}

int		ft_check_input(char *file, t_env *env)
{
	char	**split;
	char	**line;
	int		i;

	if (!(split = ft_strsplit(file, '\n')) ||
		!(line = ft_strsplit(*split, ' ')))
		return (0);
	env->len_y = ft_count_split(split);
	env->len_x = ft_count_split(line);
	ft_delsplit(line);
	i = 0;
	while (i < env->len_y)
	{
		if (env->len_x != ft_count_split(line = ft_strsplit(split[i], ' ')))
			ft_exit("File is corrupted.");
		ft_delsplit(line);
		i++;
	}
	ft_delsplit(split);
	return (1);
}

int		ft_get_input(char *file, t_env *env)
{
	char	**split;
	char	**line;
	int		i;
	int		j;

	if (!(env->fdf = (t_point ***)malloc(sizeof(t_point **) * env->len_y + 1))
		|| !(split = ft_strsplit(file, '\n')))
		return (0);
	i = -1;
	while (++i < env->len_y)
	{
		if (!(env->fdf[i] = (t_point **)malloc(sizeof(t_point *) * env->len_x))
			|| !(line = ft_strsplit(split[i], ' ')))
			return (0);
		j = -1;
		while (++j < env->len_x)
		{
			if (!(env->fdf[i][j] = ft_newpoint(j, i, ft_atoi(line[j]))))
				return (0);
		}
		ft_delsplit(line);
	}
	ft_delsplit(split);
	return (1);
}

int		ft_get_check_input(char *filename, t_env *env)
{
	int		fd;
	char	*line;
	int		gnl;
	char	*file;

	file = NULL;
	if (!(fd = open(filename, O_RDONLY)))
		return (-1);
	while ((gnl = get_next_line(fd, &line)) == 1)
	{
		if (!(file = ft_strjoinfree(file, line)) ||
			!(file = ft_strjoin(file, "\n")))
			return (-1);
	}
	if (!ft_check_input(file, env) ||
		!ft_get_input(file, env))
		return (-1);
	close(fd);
	free(file);
	return (gnl);
}

t_env	*ft_setenv(t_env *env, char **argv)
{
	if (!env ||
		ft_get_check_input(argv[1], env) == -1)
	{
		perror(strerror(errno));
		ft_exit("Fail to initialize.");
	}
	return (env);
}
