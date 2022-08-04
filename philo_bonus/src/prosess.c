/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prosess.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:04:15 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/04 14:11:31 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	*monitor(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	while (1)
	{
		if (ph->last_eat_time == 0)
			continue ;
		if (get_time() - ph->last_eat_time >= ph->die_time)
			ph_died(ph, MES_DIEAD);
		usleep(500);
	}
	pthread_exit(NULL);
}

void	create_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_num)
	{
		data->ph[i].ph_pid = fork();
		if (data->ph[i].ph_pid == 0)
		{
			pthread_create(&data->ph[i].th, NULL, monitor, &data->ph[i]);
			ph_routine(&data->ph[i]);
			pthread_join(data->ph[i].th, NULL);
			exit (EXIT_SUCCESS);
		}
		else if (data->ph[i].ph_pid == -1)
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
	// pid_t	wpid;

	create_philo(data);
	create_counter(data);
	waitpid(-1, &wstatus, 0);
	// sem_wait(data->act);
	all_kill(data);
	// def_kill(data, wpid);
}
