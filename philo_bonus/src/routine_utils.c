/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:13:55 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/07 22:18:03 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	solo(t_data *data)
{
	long long	c_time;
	long long	s_time;

	s_time = get_time();
	printf("%lld : %d %s", s_time, 1, "taken a fork\n");
	while (1)
	{
		c_time = get_time();
		if (c_time - s_time >= data->die_time)
			break ;
		usleep(100);
	}
	printf("%lld : %d %s", get_time(), 1, "died\n");
	exit(EXIT_SUCCESS);
}

void	ph_action(t_philo *philo, char *msg)
{
	sem_wait(philo->act);
	printf("%lld %d %s\n", get_time(), philo->id, msg);
	sem_post(philo->act);
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
			ph_died(philo, MES_DIEAD);
		if (start_time + action_time <= current_time)
			return ;
		usleep(50);
	}
}
