/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 05:31:14 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/04 17:27:22 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	child_kill(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_num)
	{
		if (kill(data->ph_pid[i], SIGINT) == -1)
			err_msg("KILL_ERROR");
		i++;
	}
}

void	def_kill(t_data *data, pid_t wpid)
{
	int	i;

	i = 0;
	errno = 0;
	while (i < data->ph_num)
	{
		if (data->ph_pid[i] != wpid)
		{
			if (kill(data->ph_pid[i], SIGINT) == -1)
				err_msg("KILL_ERROR");
		}
		i++;
	}
	if (kill(data->counter, SIGINT) == -1)
		err_msg("KILL_ERROR");
}
