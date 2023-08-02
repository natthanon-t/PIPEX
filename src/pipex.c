/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:00:34 by ntairatt          #+#    #+#             */
/*   Updated: 2023/08/02 11:15:13 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **argv, char **envp)
{
	int		status;
	t_pipex	var;

	if (pipe(var.end) == -1)
		error("Pipe");
	var.pid1 = fork();
	if (var.pid1 == -1)
		error("First fork");
	if (var.pid1 == 0)
		first_child(var, argv, var.end, envp);
	var.pid2 = fork();
	if (var.pid2 == -1)
		error("Second fork");
	if (var.pid2 == 0)
		second_child(var, argv, var.end, envp);
	close(var.end[0]);
	close(var.end[1]);
	waitpid(var.pid1, &status, 0);
	waitpid(var.pid2, &status, 0);
	exit(WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		error("Input parameter error");
	pipex(argv, envp);
	return (0);
}
