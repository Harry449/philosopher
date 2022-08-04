/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:34:22 by kharigae          #+#    #+#             */
/*   Updated: 2022/07/31 02:08:55 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	atoi_philo(char *str)
{
	size_t	i;
	long	num;

	i = 0;
	num = 0;
	if (str[0] == '+')
		i++;
	if (str[0] == '-')
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i] - '0');
		else
			return (-1);
		if (num > INT_MAX)
			return (-1);
		i++;
	}
	return ((int)num);
}

int	check_value(t_data *data)
{
	if (data->ph_num < 1 || data->die_time < 1 || \
		data->eat_time < 1 || data->sleep_time < 1 || \
		(data->must_eat < 1 && data->must_eat_flag))
		return (error_value());
	else
		return (SUCCESS);
}

int	store_argument(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
		return (error_usage());
	data->ph_num = atoi_philo(av[1]);
	data->die_time = atoi_philo(av[2]);
	data->eat_time = atoi_philo(av[3]);
	data->sleep_time = atoi_philo(av[4]);
	if (ac == 6)
	{
		data->must_eat = atoi_philo(av[5]);
		data->must_eat_flag = true;
	}
	else
		data->must_eat = 0;
	return (check_value(data));
}
