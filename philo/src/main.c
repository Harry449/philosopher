/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:08:31 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/07 22:18:15 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	solo(t_data *data)
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
	return (0);
}

void	mu_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_num)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->act);
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
	mu_destroy(&data);
	free(data.ph);
	free(data.fork);
	return (SUCCESS);
}
