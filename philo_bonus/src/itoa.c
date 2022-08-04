/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:49:42 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/02 01:51:43 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static int	ft_checksize(int n)
{
	int		i;

	i = 0;
	if (n > -10 && n < 10)
		return (1);
	else
	{
		while (n)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}

static void	ft_convert(char *m, int n, int size)
{
	int		sign;

	sign = 1;
	m[size] = '\0';
	if (n < 0)
		sign = -1;
	while (size-- > 0)
	{
		m[size] = '0' + n % 10 * sign;
		n /= 10;
	}
	if (sign == -1)
		m[0] = '-';
}

char	*ft_itoa(int n)
{
	int		size;
	int		flag;
	char	*m;

	size = 0;
	flag = 0;
	if (n < 0)
		flag = 1;
	size = ft_checksize(n);
	m = (char *)malloc(sizeof(char) * (size + flag + 1));
	if (!m)
		return (NULL);
	ft_convert(m, n, size + flag);
	return (m);
}
