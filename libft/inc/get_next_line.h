/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fblin <fblin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2016/01/02 13:22:38 by fblin        #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 20:24:46 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100
# include <fcntl.h>
# include "libft.h"

typedef struct	s_reader
{
	int		fd;
	char	*prev;
}				t_reader;

int				get_next_line(int const fd, char **line);

#endif
