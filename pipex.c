/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:00:34 by ntairatt          #+#    #+#             */
/*   Updated: 2023/05/30 17:08:34 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include "libft/include/ft_printf.h"
#include "libft/include/libft.h"

int	main(int argc, char **argv)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	pid1 = fork();
	if (pipe(&pid1) == -1)
	{
		ft_printf("fork of pid1 error!");
		return (1);
	}
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/bin", &argv[2], NULL);
	}
	pid2 = fork();
	if (pipe(&pid2) == -1)
	{
		ft_printf("fork of pid2 error!");
		return (1);
	}
	if (pid1 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/bin", &argv[3], NULL);
	}
	close(fd[0]);
	close(fd[1]);	
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}