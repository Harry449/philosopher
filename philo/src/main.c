/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:08:31 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/06 20:36:12 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	solo(t_data *data)
{
	long	time;

	time = get_time();
	printf("%ld : %d %s", time, 1, "taken a fork\n");
	printf("%ld : %d %s", time + data->die_time, 1, "died\n");
	return (0);
}

void	th_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_num)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->act);
	pthread_mutex_destroy(&data->last_eat);
	pthread_mutex_destroy(&data->mu_alive);
}

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	if (store_argument(ac, av, &data))
		return (ERROR);
	if (data.ph_num == 1)
		return (solo(&data));
	if (init_philo(&data))
		return (err_msg("MALLOC_ERROR\n"));
	if (init_thread(&data))
		return (err_msg("MALLOC_ERROR\n"));
	if (create_thread(&data))
		return (ERROR);
	th_destroy(&data);
	free(data.ph);
	free(data.fork);
	return (SUCCESS);
}
