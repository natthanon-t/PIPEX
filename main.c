#include <stdio.h>
#include "include/pipex.h"

int main(int argc, char **argv)

/* Example of using argument command line */

//{
//	int i =0;
//	/* argv[0] - program's name */ 
//	while (argv[i])
//	{
//		printf("argv[%d] = %s\n", i, argv[i]);
//		i++;
//	}
//}

/* Example of using pipe */

//{
//	int fd[2];

//	pipe(fd);
//	int id = fork();
//	if (id == 0)
//	{
//		close(fd[0]);
//		int x;
//		printf("Input number of X: ");
//		scanf("%d", &x);
//		write(fd[1], &x, sizeof(int));
//		close(fd[1]);
//		printf("Sending to parent Process....\n");
//		sleep(1);
//	}
//	else
//	{
//		wait(NULL);
//		close(fd[1]);
//		int y;
//		read(fd[0], &y, sizeof(int));
//		close(fd[0]);
//		printf("x = %d\n", y);
//	}
//}

/* Example of using execve */

{
	char *path[] = {"/bin/ls", "-l", NULL};
	execve(path[0], path, "test.txt");
}
