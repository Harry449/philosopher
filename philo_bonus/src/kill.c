/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 05:31:14 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/04 14:22:14 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	child_kill(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_num)
	{
		kill(data->ph_pid[i], SIGINT);
		i++;
	}
}

void	def_kill(t_data *data, pid_t wpid)
{
	int	i;

	i = 0;
	while (i < data->ph_num)
	{
		if (data->ph_pid[i] != wpid)
			kill(data->ph_pid[i], SIGINT);
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
		kill(data->ph_pid[i], SIGINT);
		i++;
	}
	kill(data->counter, SIGINT);
}
