#include "include/pipex.h"
#include "libft/include/libft.h"
#include "libft/include/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp)

/* Example of using argument command line */

{
	int i =0;
	/* argv[0] - program's name */
	while (argv[i])
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}
	printf("argc = %d\n", argc);
}

/* Example of using pipe function */

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

//{
//	char *path[] = {"/bin/ls", "-l", NULL};
//	execve(path[0], path, NULL);
//}

/* Example of using environment vairable */

//{
//	int i = -1;
//	while (envp[++i])
//		printf("no%d %s\n", i, envp[i]);
//}

/* Example of using dup/dup2 */

//{
//	int fd = open("test.txt", O_WRONLY);
//	dup2(fd, 1);
//	close(fd);
//	printf("Test after dup2\n");
//	printf("Test after dup2 no.2");
//	char *path[] = {"/bin/ls", "-l", NULL};
//	execve(path[0], path, NULL);
//}

/* Simulating of Pipe Operator */

//{
//    int fd[2];
//    if (pipe(fd) == -1) {
//        return;
//    }

//    int pid1 = fork();
//    if (pid1 < 0) {
//        return 2;
//    }

//    if (pid1 == 0) {
//        // Child process 1 (ping)
//        dup2(fd[1], STDOUT_FILENO);
//        close(fd[0]);
//        close(fd[1]);
//        execlp("ping", "ping", "-c", "5", "google.com", NULL);
//    }

//    int pid2 = fork();
//    if (pid2 < 0) {
//        return 3;
//    }

//    if (pid2 == 0) {
//        // Child process 2 (grep)
//        dup2(fd[0], STDIN_FILENO);
//        close(fd[0]);
//        close(fd[1]);
//        execlp("grep", "grep", "rtt", NULL);
//    }

//    close(fd[0]);
//    close(fd[1]);

//    waitpid(pid1, NULL, 0);
//    waitpid(pid2, NULL, 0);

//    return 0;
//}

/* Example of using perror */

//{
//	perror("fork");
//}

/* Example of using access */

//{
//	// success return 0 else 1
//	int i = -2;
//	while (++i < 10)
//		printf("i = %d, Access Return = %d\n", i, access("/bin/ls", i));
//}

/* Example of using open */

//{
//	int fd = open("a.out", O_RDONLY);
//	printf("fd of a.out = %d\n", fd);
//	char *test;
//	int i = 5;
//	while (i--)
//	{
//		test = get_next_line(fd);
//		printf("%s", test);
//		free(test);
//	}
//}
