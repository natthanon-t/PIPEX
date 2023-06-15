#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

//int main() 
//{
//	pid_t pid;
//	int status;

//	pid = fork();
//	if (pid == 0) 
//	{
//	  printf("I'm Child process\n");
//	  exit(127);
//	} 
//// Parent process
//	exit(WEXITSTATUS(status));
//	return 0;
//}
#include "libft.h"
int main(int argc, char **argv, char **envp)
{
	printf("test %d\n", open(argv[4], O_TRUNC | O_WRONLY | O_CREAT, 0644));
}