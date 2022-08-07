# include <stdio.h>
# include <pthread.h>

//ctrl-Cで終了するとhelgrindでエラーになる
//リークもエラーでるが問題なし
void	*routine(void *arg)
{
	pthread_mutex_t *mu;

	mu = (pthread_mutex_t *)arg;
	pthread_mutex_lock(mu);
	while(1);
	pthread_mutex_unlock(mu);
	pthread_exit(NULL);
}

int	main(void)
{
	pthread_t th;
	pthread_mutex_t mu;

	pthread_mutex_init(&mu, NULL);
	pthread_create(&th, NULL, routine, &mu);
	pthread_join(th, NULL);
	pthread_mutex_destroy(&mu);
	return (0);
}
