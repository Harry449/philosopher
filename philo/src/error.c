/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:17:09 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/03 21:56:04 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	error_value(void)
{
	printf(PRINT_ERROR);
	printf("Cannot handle 0 , negative values and not number.\n");
	return (ERROR);
}

int	err_msg(char *msg)
{
	printf("%s", msg);
	return (ERROR);
}

int	free_data(t_data *data)
{
	free(data->ph);
	return (ERROR);
}

int	error_usage(void)
{
	printf(PRINT_ERROR);
	printf("USAGE\t\t:\t./philo die eat sleep [must_eat]\n");
	printf("die\t\t:\tTime to die (ms)\n");
	printf("eat\t\t:\tTime to eat (ms)\n");
	printf("sleep\t\t:\tTime to sleep (ms)\n");
	printf("[must eat]\t:\tNumber of times each philosopher must eat (option)\n");
	return (ERROR);
}
