/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:55:42 by ntairatt          #+#    #+#             */
/*   Updated: 2023/07/31 20:43:03 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipex var, char **argv, int *end, char **envp)
{
	int		file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		message_error(strerror(errno), argv[1]);
		exit(EXIT_FAILURE);
	}
	var.cmd = full_cmd(var, argv[2], envp);
	if (!var.cmd)
		cmd_error(argv[2]);
	dup2(file1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(file1);
	close(end[0]);
	execve(var.cmd[0], var.cmd, envp);
	free_2(var.cmd);
	error("Execve");
}

void	second_child(t_pipex var, char **argv, int *end, char **envp)
{
	int		file2;

	file2 = open(argv[4], O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (file2 == -1)
	{
		message_error(strerror(errno), argv[4]);
		exit(EXIT_FAILURE);
	}
	var.cmd = full_cmd(var, argv[3], envp);
	if (!var.cmd)
		cmd_error(argv[3]);
	dup2(end[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(file2);
	close(end[1]);
	execve(var.cmd[0], var.cmd, envp);
	free_2(var.cmd);
	error("Execve");
}
