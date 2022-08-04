/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 05:31:14 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/04 14:11:12 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	child_kill(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_num)
	{
		kill(data->ph[i].ph_pid, SIGINT);
		i++;
	}
}

void	def_kill(t_data *data, pid_t wpid)
{
	int	i;

	i = 0;
	while (i < data->ph_num)
	{
		if (data->ph[i].ph_pid != wpid)
			kill(data->ph[i].ph_pid, SIGINT);
		i++;
	}
	if (data->counter != wpid)
		kill(data->counter, SIGINT);
}

void	all_kill(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_num)
	{
		kill(data->ph[i].ph_pid, SIGINT);
		i++;
	}
	kill(data->counter, SIGINT);
}
