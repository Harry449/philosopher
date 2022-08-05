/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:07:57 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/05 13:47:04 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ph_died(t_philo *philo, char *msg)
{
	long	time;

	time = get_time();
	sem_wait(philo->act);
	printf("%ld %d %s\n", time, philo->id, msg);
	exit(EXIT_SUCCESS);
}

void	eating(t_philo *ph)
{
	sem_wait(ph->act);
	printf("%ld %d %s\n", get_time(), ph->id, MES_EAT);
	sem_post(ph->eat);
	usleep(100);
	sem_post(ph->act);
	sem_wait(ph->last_eat);
	ph->last_eat_time = get_time();
	ph_time(ph, ph->eat_time);
	sem_post(ph->last_eat);
	sem_post(ph->fork);
	sem_post(ph->fork);
}

void	taken_a_fork(t_philo *philo)
{
	if (philo->id % 2)
		usleep(500);
	sem_wait(philo->fork);
	ph_action(philo, MES_FORK);
	sem_wait(philo->fork);
	ph_action(philo, MES_FORK);
}

void	ph_routine(t_philo *philo)
{
	sem_wait(philo->last_eat);
	philo->last_eat_time = get_time();//
	sem_post(philo->last_eat);
	while (1)
	{
		taken_a_fork(philo);
		eating(philo);
		ph_action(philo, MES_SLEEP);
		ph_time(philo, philo->sleep_time);
		ph_action(philo, MES_THINK);
	}
}
