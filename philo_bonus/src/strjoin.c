/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:51:46 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/02 01:52:24 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		c;
	int		ss1;
	int		ss2;
	char	*m;

	i = 0;
	c = 0;
	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	m = (char *)malloc(sizeof(char) * (ss1 + ss2 + 1));
	if (!m)
		return (NULL);
	while (s1[i] != '\0')
	{
		m[i] = s1[i];
		i++;
	}
	while (s2[c] != '\0')
	{
		m[i + c] = s2[c];
		c++;
	}
	m[i + c] = '\0';
	return (m);
}
