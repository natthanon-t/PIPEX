/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:00:34 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/03 17:54:38 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include "libft/include/ft_printf.h"
#include "libft/include/libft.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status;
	int		end[2];
	char	*cmd1[] = {"/bin/cat", "test1.txt", NULL};
	char	*cmd2[] = {"/usr/bin/wc", "-l", NULL};

	int file1 = open("test1.txt", O_WRONLY | O_CREAT, 0777);
	int file2 = open("test2.txt", O_WRONLY | O_CREAT, 0777);
	//if (argc != 5)
	//	return (1);
	//cmd1 = ft_split(argv[2], ' ');
	//cmd2 = ft_split(argv[3], ' ');
	if (pipe(end) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid1 = fork();
	//if (pid1 == -1)
	//	return (perror("Fork1"));
	if (pid1 == 0)
	{
		dup2(file1, STDIN_FILENO);
		dup2(end[1], STDOUT_FILENO);
		close(end[0]);
		close(file2);
		execve(cmd1[0], cmd1, envp);
	}
	pid2 = fork();
	//if (pid2 == -1)
	//	return (perror("Fork2"));
	if (pid2 == 0)
	{
		dup2(end[0], STDIN_FILENO);
		dup2(file2, STDOUT_FILENO);
		close(end[1]);
		close(file1);
		execve(cmd2[0], cmd2, envp);
	}
	close(end[0]);
	close(end[1]);
	close(file1);
	close(file2);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}