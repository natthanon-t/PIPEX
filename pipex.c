/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:00:34 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/02 17:54:58 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include "libft/include/ft_printf.h"
#include "libft/include/libft.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	char	**cmd1;
	char	**cmd2;
	char *path_l[] = {"/bin/ls", "-la", NULL};
	char *path_c[] = {"/bin/cat", "Makefile", NULL};
	
	if (argc != 5)
		return (1);
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	if (pipe(fd) == -1)
	{
		ft_printf("pipe error");
		return (1);
	}
	pid1 = fork();
	if (pid1 == 0)
	{
		//dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(path_l[0], path_l, NULL);
	}
	pid2 = fork();
	//if (pipe(&pid2) == -1)
	//{
	//	ft_printf("fork of pid2 error!");
	//	return (1);
	//}
	if (pid1 == 0)
	{
		ft_printf("child here");
		//dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(path_c[0], path_c, NULL);
	}
	close(fd[0]);
	close(fd[1]);	
	waitpid(pid1, NULL, 0);
	//waitpid(pid2, NULL, 0);
	return (0);
}