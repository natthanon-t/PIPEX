/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:55:42 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/16 14:59:54 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char **argv, int *end, char **envp)
{
	char	**cmd;
	int		file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		message_error("no such file or directory: ", argv[1]);
		exit(EXIT_SUCCESS);
	}
	cmd = full_cmd(argv[2], envp);
	if (!cmd)
		cmd_error(argv[2], cmd);
	dup2(file1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	if (execve(cmd[0], cmd, envp) == -1)
	{
		free_2(cmd);
		error("execve of first child\n");
	}
}

void	second_child(int file2, int *end, char **argv, char **envp)
{
	char	**cmd;

	cmd = full_cmd(argv[3], envp);
	if (!cmd)
		cmd_error(argv[3], cmd);
	dup2(end[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(end[1]);
	if (execve(cmd[0], cmd, envp) == -1)
	{
		free_2(cmd);
		error("execve of second child\n");
	}
}
