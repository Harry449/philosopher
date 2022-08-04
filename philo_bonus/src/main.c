/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 01:34:09 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/03 03:35:46 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

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
	free(data.ph);
	return (0);
}
