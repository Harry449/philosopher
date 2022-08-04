/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:35:25 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/03 21:59:49 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_data(t_data *data)
{
	data->ph_num = 0;
	data->die_time = 0;
	data->eat_time = 0;
	data->sleep_time = 0;
	data->must_eat = 0;
	data->fin_must_eat = 0;
	data->must_eat_flag = false;
	data->monitor = NULL;
	data->fork = NULL;
	data->ph = NULL;
	data->alive = true;
}

int	init_philo(t_data *data)
{
	int		i;

	data->ph = (t_philo *)malloc(sizeof(t_philo) * data->ph_num);
	if (!data->ph)
		return (1);
	i = 0;
	while (i < data->ph_num)
	{
		data->ph[i].ph_num = data->ph_num;
		data->ph[i].die_time = data->die_time;
		data->ph[i].eat_time = data->eat_time;
		data->ph[i].sleep_time = data->sleep_time;
		data->ph[i].must_eat = data->must_eat;
		data->ph[i].alive = &data->alive;
		data->ph[i].last_eat_time = 0;
		data->ph[i].eat_num = 0;
		data->ph[i].fin_must_eat = &data->fin_must_eat;
		data->ph[i].id = i + 1;
		i++;
	}
	return (0);
}

int	init_thread(t_data *d)
{
	int	i;

	i = 0;
	d->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * d->ph_num);
	if (!d->fork)
		return (free_data(d));
	pthread_mutex_init(&d->act, NULL);
	while (i < d->ph_num)
	{
		pthread_mutex_init(&d->fork[i], NULL);
		d->ph[i].left_fork = &d->fork[i];
		d->ph[i].right_fork = &d->fork[(i - 1 + d->ph_num) % d->ph_num];
		d->ph[i].act = &d->act;
		i++;
	}
	return (0);
}
