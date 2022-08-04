/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:47:34 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/01 01:45:04 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ph_died(t_philo *ph)
{
	long	time;

	time = get_time();
	pthread_mutex_lock(ph->act);
	if (*ph->alive)
		printf("%ld %d %s", time, ph->id, "died\n");
	*ph->alive = false;
	pthread_mutex_unlock(ph->act);
}

void	*monitor(void *arg)
{
	int		i;
	t_data	*data;

	data = arg;
	while (data->alive)
	{
		i = 0;
		while (i < data->ph_num)
		{
			if (data->ph[i].last_eat_time == 0)
				continue ;
			if (get_time() - data->ph[i].last_eat_time >= data->ph[i].die_time)
			{
				ph_died(&data->ph[i]);
				pthread_exit(NULL);
			}
			i++;
		}
		usleep(200);
	}
	pthread_exit(NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat_time = get_time();
	while (*philo->alive)
	{
		take_a_fork(philo);
		eating(philo);
		ph_action(philo, "is sleeping\n");
		ph_time(philo, philo->sleep_time);
		ph_action(philo, "is thinking\n");
	}
	pthread_exit(NULL);
}

int	create_thread(t_data *data)
{
	int	i;
	int	pth_ret;

	i = 0;
	while (i < data->ph_num)
	{
		pth_ret = pthread_create(&data->ph[i].th, NULL, routine, &data->ph[i]);
		if (pth_ret)
			return (err_msg("CREATE_ERR\n"));
		i++;
	}
	pthread_create(&data->monitor, NULL, monitor, data);
	i = 0;
	while (i < data->ph_num)
	{
		pth_ret = pthread_join(data->ph[i].th, NULL);
		if (pth_ret)
			return (err_msg("JOIN_ERR\n"));
		i++;
	}
	pthread_join(data->monitor, NULL);
	return (SUCCESS);
}
