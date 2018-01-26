/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:24 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 17:35:24 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(unsigned int x)
{
	int len;

	len = 1;
	while (x /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char			*ret;
	int				neg;
	int				ret_size;
	unsigned int	n_long;

	n_long = (long int)n;
	neg = n < 0;
	if (neg)
		n_long = -n;
	ret_size = ft_intlen(n_long);
	if (!(ret = (char *)ft_memalloc(sizeof(ret) * ret_size + 2)))
		return (NULL);
	ret[ret_size + 1] = '\0';
	ret[0] = '-';
	while (ret_size > 0)
	{
		ret[ret_size--] = ((n_long % 10) + '0');
		n_long /= 10;
	}
	if (!neg)
		ret++;
	return (ret);
}
