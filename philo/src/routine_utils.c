/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:02:54 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/06 03:59:20 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ph_action(t_philo *ph, char *msg)
{
	long	time;

	time = get_time();
	pthread_mutex_lock(ph->act);
	pthread_mutex_lock(ph->mu_alive);
	if (*ph->alive)
		printf("%ld %d %s", time, ph->id, msg);
	pthread_mutex_unlock(ph->mu_alive);
	pthread_mutex_unlock(ph->act);
}

long	get_time(void)
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
			ph_died(philo);
		if (start_time + action_time <= current_time)
			return ;
		usleep(100);
	}
}
