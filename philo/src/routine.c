/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:50:13 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/06 03:59:07 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	count_eat(t_philo *philo)
{
	philo->eat_num++;
	if (philo->eat_num == philo->must_eat)
		++*philo->fin_must_eat;
	pthread_mutex_lock(philo->mu_alive);
	if (*philo->fin_must_eat == philo->ph_num)
		*philo->alive = false;
	pthread_mutex_unlock(philo->mu_alive);
}

void	ph_act_eat(t_philo *ph, char *msg)
{
	pthread_mutex_lock(ph->act);
	ph->last_eat_time = get_time();
	pthread_mutex_lock(ph->mu_alive);
	if (*ph->alive)
		printf("%ld %d %s", ph->last_eat_time, ph->id, msg);
	pthread_mutex_unlock(ph->mu_alive);
	if (ph->must_eat)
		count_eat(ph);
	pthread_mutex_unlock(ph->act);
}

void	eating(t_philo *philo)
{
	ph_act_eat(philo, "is eating\n");
	ph_time(philo, philo->eat_time);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	take_a_fork(t_philo *philo)
{
	if (philo->id % 2)
		pthread_mutex_lock(philo->left_fork);
	else
	{
		usleep(200);
		pthread_mutex_lock(philo->right_fork);
	}
	ph_action(philo, "has taken a fork\n");
	if (philo->id % 2)
	{
		usleep(200);
		pthread_mutex_lock(philo->right_fork);
	}
	else
		pthread_mutex_lock(philo->left_fork);
	ph_action(philo, "has taken a fork\n");
}
