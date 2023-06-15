/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:55:42 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/15 16:04:31 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char **argv, int *end, char **envp)
{
	char	**cmd;
	int		file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		message_error("no such file or directory: ", argv[1], 0);
	cmd = full_cmd(argv[2], envp);
	if (!cmd)
	{
		cmd = ft_split(argv[2], ' ');
		if (ft_strrchr(cmd[0], '/'))
			ft_printf("no such file or directory: %s\n", cmd[0]);
		else
			ft_printf("command not found: %s\n", cmd[0]);
		free_2(cmd);
		exit(0);
	}
	dup2(file1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	if (execve(cmd[0], cmd, envp) == -1)
	{
		free_2(cmd);
		error("execve of first child");
	}
}

void	second_child(int file2, int *end, char **argv, char **envp)
{
	char	**cmd;

	cmd = full_cmd(argv[3], envp);
	if (!cmd)
	{
		cmd = ft_split(argv[3], ' ');
		if (ft_strrchr(cmd[0], '/'))
			ft_printf("no such file or directory: %s\n", cmd[0]);
		else
			ft_printf("command not found: %s\n", cmd[0]);
		free_2(cmd);
		exit(127);
	}
	dup2(end[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(end[1]);
	if (execve(cmd[0], cmd, envp) == -1)
	{
		free_2(cmd);
		error("execve of second child");
	}
}
