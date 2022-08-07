/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prosess.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:04:15 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/07 22:51:10 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	*monitor(void *arg)
{
	t_philo	*ph;
	int		time;

	ph = (t_philo *)arg;
	while (1)
	{
		sem_wait(ph->last_eat);
		time = get_time() - ph->last_eat_time;
		sem_post(ph->last_eat);
		if (time >= ph->die_time)
			ph_died(ph, MES_DIEAD);
		usleep(500);
	}
}

void	create_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_num)
	{
		data->ph_pid[i] = fork();
		if (data->ph_pid[i] == 0)
		{
			pthread_create(&data->ph[i].th, NULL, monitor, &data->ph[i]);
			ph_routine(&data->ph[i]);
			pthread_join(data->ph[i].th, NULL);
			exit (EXIT_SUCCESS);
		}
		else if (data->ph_pid[i] == -1)
			fork_error(data, i);
		i++;
	}
}

void	create_counter(t_data *data)
{
	data->counter = fork();
	if (data->counter == 0 && data->must_eat)
	{
		eat_counter(data);
		exit (EXIT_SUCCESS);
	}
	else if (data->counter == 0 && !(data->must_eat))
	{
		counter(data);
		exit (EXIT_SUCCESS);
	}
	else if (data->counter == -1)
		fork_error(data, data->ph_num);
}

void	create_prosess(t_data *data)
{
	int		wstatus;
	int		wpid;

	create_philo(data);
	create_counter(data);
	wpid = waitpid(-1, &wstatus, 0);
	if (wstatus != 256)
		def_kill(data, wpid);
}
