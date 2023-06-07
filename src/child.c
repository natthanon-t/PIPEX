/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:55:42 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/07 15:10:46 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	first_child(char **argv, int *end, char **envp)
{
	char	**cmd;
	int		file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		message_error("no such file or directory: ", argv[1]);
	cmd = full_cmd(argv[2], envp);
	dup2(file1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(file1);
	if (execve(cmd[0], cmd, envp) == -1)
	{
		free_2(cmd);
		error("execve of first child");
	}
}

void	second_child(int file2, int *end, char **cmd, char **envp)
{
	dup2(end[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(end[1]);
	if (execve(cmd[0], cmd, envp) == -1)
	{
		free_2(cmd);
		error("execve of second child");
	}
}
