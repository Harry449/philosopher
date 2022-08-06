# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <semaphore.h>
# include <stdlib.h>


void	child(void)
{
	printf("child prosess\n");
}
int	main(void)
{
	sem_t	*sem;
	int		wstatus;

	sem_unlink("/test");
	sem = sem_open("/test", O_CREAT, 0600, 0);
	sem_unlink("/test");
	pid_t pid = fork();
	if (pid == 0)
	{
		sem_wait(sem);
		child();
		exit(0);
	}
	printf("post : child execution\n");
	sem_post(sem);
	waitpid(-1, &wstatus, 0);
	return (0);
}
