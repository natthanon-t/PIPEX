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

int main(int argc, char **argv, char **envp)
{
	int i =0;
	while (strncmp(envp[i], "PATH", 4) != 0 && envp[i])
	{
		printf("i = %d\n", i);
		printf("envp = %s\n", envp[i++]);
	}
	printf("tes2asdasdasdas\n");
}