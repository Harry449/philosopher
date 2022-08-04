/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:09:34 by kharigae          #+#    #+#             */
/*   Updated: 2022/08/04 17:36:25 by kharigae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdbool.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/time.h>
# include <limits.h>
# include <stdlib.h>
# include <errno.h>
# include <pthread.h>

# define SEM_FORK "/fork"
# define SEM_EAT "/eat"
# define SEM_ACT "/act"
# define MES_FORK "has taken a fork"
# define MES_EAT "is eating"
# define MES_SLEEP "is sleeping"
# define MES_THINK "is thinking"
# define MES_DIEAD "died"
# define PRINT_ERROR "\x1b[31mERROR!\n\x1b[0m"
# define ERR_VALUE "Cannot handle 0 , negative values and not number.\n"
# define ERR_SEM "Semaphore error\n"
# define ERR_MALLOC "Malloc error\n"
# define ERROR 1
# define SUCCESS 0

typedef struct s_philo
{
	int			ph_num;
	int			die_time;
	int			eat_time;
	int			sleep_time;
	int			must_eat;
	int			eat_num;
	long		last_eat_time;
	int			id;
	pthread_t	th;
	sem_t		*fork;
	sem_t		*eat;
	sem_t		*act;
}	t_philo;

// philo_num		= 哲学者の人数
// die_time			= 死ぬまでの時間
// eat_time			= 食事にかかる時間
// sleep_time		= 睡眠時間
// must_eat			= 食事しなければいけない回数（option）
// eat_num			= 食事回数
// fin_must_eat		= 指定の食事回数が終わった人数
// last_eat_time	= 最後に食事した時間
// id				= 哲学者の識別番号
// ph_pid			= fork()の返り値を格納する（プロセス）
// fork				= フォークのセマフォ
// eat				= 食事のセマフォ
// act				= 行動のセマフォ

typedef struct s_data
{
	int		ph_num;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		must_eat;
	bool	must_eat_flag;
	pid_t	counter;
	sem_t	*fork;
	sem_t	*eat;
	sem_t	*act;
	t_philo	*ph;
	pid_t	*ph_pid;
}	t_data;

// must_eat_flag	= must_eatが指定されているかのflag
// monitor			= 哲学者を監視するプロセス

// error.c
void	error_usage(void);
void	err_msg(char *msg);
void	fork_error(t_data *data, int id);

// init.c
void	create_sem(t_data *data);
void	init_philo(t_data *data);
void	init_data(t_data *data);

// itoa.c
char	*ft_itoa(int n);

//kill.c
void	child_kill(t_data *data);
void	all_kill(void);
void	def_kill(t_data *data, pid_t wpid);

// counter.c
void	eat_counter(t_data *data);
void	counter(t_data *data);

// prosess.c
void	create_prosess(t_data *data);

// routine_util.c
long	get_time(void);
void	solo(t_data *data);
void	ph_action(t_philo *philo, char *msg);
void	ph_time(t_philo *philo, int action_time);

// routine.c
void	ph_died(t_philo *philo, char *msg);
void	taken_a_fork(t_philo *philo);
void	eating(t_philo *philo);
void	ph_routine(t_philo *philo);

// store_argument.c
void	store_argument(int ac, char **av, t_data *data);

//strjoin.c
char	*ft_strjoin(char const *s1, char const *s2);
#endif
