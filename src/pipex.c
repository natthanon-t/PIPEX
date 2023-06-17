/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:00:34 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/16 21:38:53 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status;
	int		end[2];

	if (pipe(end) == -1)
		error("Pipe");
	pid1 = fork();
	if (pid1 == -1)
		error("First fork");
	if (pid1 == 0)
		first_child(argv, end, envp);
	pid2 = fork();
	if (pid2 == -1)
		error("Second fork");
	if (pid2 == 0)
		second_child(end, argv, envp);
	close(end[0]);
	close(end[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	exit(WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		error("Input parameter error");
	pipex(argv, envp);
}
