/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 01:34:09 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/07 15:13:35 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	destroy_sem(t_data *data)
{
	int	i;

	i = 0;
	sem_close(data->act);
	sem_close(data->fork);
	while (i < data->ph_num)
	{
		sem_close(data->ph[i].eat);
		sem_close(data->ph[i].last_eat);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	store_argument(ac, av, &data);
	if (data.ph_num == 1)
		solo(&data);
	create_sem(&data);
	init_philo(&data);
	create_prosess(&data);
	destroy_sem(&data);
	free(data.ph);
	free(data.ph_pid);
	return (0);
}
