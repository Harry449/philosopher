/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:07:05 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/04 14:09:21 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	eat_counter(t_data *data)
{
	int	i;
	int	fin;

	fin = 0;
	while (1)
	{
		i = 0;
		while (i < data->ph_num)
		{
			sem_wait(data->ph[i].eat);
			++data->ph[i].eat_num;
			if (data->ph[i].eat_num == data->must_eat)
				++fin;
			if (fin == data->ph_num)
				exit(0);
			i++;
		}
	}
}

void	counter(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->ph_num)
		{
			sem_wait(data->ph[i].eat);
			i++;
		}
	}
}
