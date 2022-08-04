/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:04:56 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/04 13:42:27 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	init_data(t_data *data)
{
	data->ph_num = 0;
	data->die_time = 0;
	data->eat_time = 0;
	data->sleep_time = 0;
	data->must_eat = 0;
	data->must_eat_flag = false;
}

sem_t	*sem_set(char *name, int i)
{
	char	*id;
	char	*new_name;
	sem_t	*ret;

	id = ft_itoa(i);
	new_name = ft_strjoin(name, id);
	sem_unlink(new_name);
	ret = sem_open(new_name, O_CREAT, S_IRUSR | S_IWUSR, 0);
	if (ret == SEM_FAILED)
		err_msg(ERR_SEM);
	sem_unlink(new_name);
	free(id);
	free(new_name);
	return (ret);
}

void	init_philo(t_data *data)
{
	int		i;

	data->ph = (t_philo *)malloc(sizeof(t_philo) * data->ph_num);
	if (!data->ph)
		err_msg(ERR_MALLOC);
	i = 0;
	while (i < data->ph_num)
	{
		data->ph[i].ph_num = data->ph_num;
		data->ph[i].die_time = data->die_time;
		data->ph[i].eat_time = data->eat_time;
		data->ph[i].sleep_time = data->sleep_time;
		data->ph[i].must_eat = data->must_eat;
		data->ph[i].last_eat_time = 0;
		data->ph[i].eat_num = 0;
		data->ph[i].id = i + 1;
		data->ph[i].fork = data->fork;
		data->ph[i].eat = sem_set("/eat", i);
		data->ph[i].act = data->act;
		i++;
	}
}

void	create_sem(t_data *d)
{
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_ACT);
	d->fork = sem_open(SEM_FORK, O_CREAT, S_IRUSR | S_IWUSR, d->ph_num);
	d->act = sem_open(SEM_ACT, O_CREAT, S_IRUSR | S_IWUSR, 1);
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_ACT);
	if (d->fork == SEM_FAILED || d->act == SEM_FAILED)
		err_msg(ERR_SEM);
}
