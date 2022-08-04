/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:09:31 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/05 06:02:07 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/types.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>

# define PRINT_ERROR "\x1b[31mERROR!\n\x1b[0m"
# define ERROR 1
# define SUCCESS 0

typedef struct s_philo
{
	int				ph_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	int				eat_num;
	int				*fin_must_eat;
	long			last_eat_time;
	bool			*alive;
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*act;
	pthread_mutex_t	*last_eat;
	pthread_mutex_t	*mu_alive;
	pthread_t		th;
}	t_philo;

// philo_num		= 哲学者の人数
// die_time			= 死ぬまでの時間
// eat_time			= 食事にかかる時間
// sleep_time		= 睡眠時間
// must_eat			= 食事しなければいけない回数（option）
// eat_num			= 食事回数
// fin_must_eat		= 指定の食事回数が終わった人数
// last_eat_time	= 最後に食事した時間
// alive			= 生存確認
// id				= 哲学者の識別番号
// left_fork		= 左にあるフォークのロック
// right_fork		= 右にあるフォークのロック
// act				= 行動中にロックする
// thread			= 哲学者＝スレッド

typedef struct s_data
{
	int				ph_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	int				fin_must_eat;
	bool			must_eat_flag;
	bool			alive;
	pthread_t		monitor;
	pthread_mutex_t	*fork;
	pthread_mutex_t	act;
	pthread_mutex_t	last_eat;
	pthread_mutex_t	mu_alive;
	t_philo			*ph;
}	t_data;

// monitor	= 哲学者の生存確認
// fork		= フォークの本数分の配列
// philo	= 哲学者の人数分の配列

//create_thread.c
void	ph_died(t_philo *ph);
int		create_thread(t_data *data);
//error.c
int		error_value(void);
int		err_msg(char *msg);
int		free_data(t_data *data);
int		error_usage(void);
//init.c
void	init_data(t_data *data);
int		init_philo(t_data *data);
int		init_thread(t_data *d);
//routine.c
void	eating(t_philo *philo);
void	take_a_fork(t_philo *philo);
//routine_util.c
void	ph_action(t_philo *ph, char *msg);
long	get_time(void);
void	ph_time(t_philo *philo, int action_time);
//store_argument.c
int		store_argument(int ac, char **av, t_data *data);
#endif
