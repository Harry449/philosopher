/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:02:54 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/07 18:18:42 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ph_action(t_philo *ph, char *msg)
{
	long long	time;

	time = get_time();
	pthread_mutex_lock(ph->act);
	if (*ph->alive)
		printf("%lld %d %s", time, ph->id, msg);
	pthread_mutex_unlock(ph->act);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ph_time(t_philo *philo, int action_time)
{
	long	start_time;
	long	current_time;

	start_time = get_time();
	while (1)
	{
		current_time = get_time();
		if (current_time - philo->last_eat_time >= philo->die_time)
		{
			pthread_mutex_lock(philo->act);
			ph_died(philo);
			pthread_mutex_unlock(philo->act);
			return ;
		}
		if (start_time + action_time <= current_time)
			return ;
		usleep(100);
	}
}
