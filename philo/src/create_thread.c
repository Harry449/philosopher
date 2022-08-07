/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:47:34 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/07 18:19:24 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ph_died(t_philo *ph)
{
	long long	time;

	time = get_time();
	if (*ph->alive)
	{
		printf("%lld %d %s", time, ph->id, "died\n");
		*ph->alive = false;
	}
}

void	*monitor(void *arg)
{
	int		i;
	t_data	*data;

	data = arg;
	while (1)
	{
		i = -1;
		while (++i < data->ph_num)
		{
			pthread_mutex_lock(&data->act);
			if (data->ph[i].last_eat_time == 0)
			{
				pthread_mutex_unlock(&data->act);
				continue ;
			}
			if (get_time() - data->ph[i].last_eat_time >= data->ph[i].die_time)
			{
				ph_died(&data->ph[i]);
				pthread_mutex_unlock(&data->act);
				pthread_exit(NULL);
			}
			pthread_mutex_unlock(&data->act);
			usleep(100);
		}
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->act);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(philo->act);
	while (1)
	{
		pthread_mutex_lock(philo->act);
		if (*philo->alive == false)
			break ;
		pthread_mutex_unlock(philo->act);
		take_a_fork(philo);
		eating(philo);
		ph_action(philo, "is sleeping\n");
		ph_time(philo, philo->sleep_time);
		ph_action(philo, "is thinking\n");
	}
	pthread_mutex_unlock(philo->act);
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
