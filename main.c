#include "include/pipex.h"
#include "libft/include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp)
{
	//char **path_all = split_path(envp);
	//char *path = find_path(path_all, "grep");
	char **str;

	str = full_cmd("ls -b -c", envp);
	for (int i =0; str[i]; i++)
		printf("path of cmd = %s\n", str[i]);
	free_2(str);
	//printf("path of ls = %s\n", path);
}