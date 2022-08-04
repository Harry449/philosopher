/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:10:15 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/02 19:43:55 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	err_msg(char *msg)
{
	printf(PRINT_ERROR);
	printf("%s", msg);
	exit(EXIT_FAILURE);
}

void	error_usage(void)
{
	printf(PRINT_ERROR);
	printf("USAGE\t\t:\t./philo die eat sleep [must_eat]\n");
	printf("die\t\t:\tTime to die (ms)\n");
	printf("eat\t\t:\tTime to eat (ms)\n");
	printf("sleep\t\t:\tTime to sleep (ms)\n");
	printf("[must eat]\t:\tNumber of times each philosopher must eat (option)\n");
	exit(EXIT_FAILURE);
}

void	fork_error(t_data *data, int id)
{
	int	i;

	i = 0;
	while (i < id)
	{
		kill(data->ph[i].ph_pid, SIGINT);
		i++;
	}
	err_msg("FORK_ERROR");
}
