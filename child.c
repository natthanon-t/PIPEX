/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:55:42 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/03 22:01:51 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	first_child(int file1, int file2, int *end, char *cmd1, char **envp)
{
	char	**path_cmd;
	char	*cmd;

	path_cmd = split_path(envp);
	cmd = find_path(path_cmd, cmd1);
	dup2(file1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(file2);
	execve(cmd, path_cmd, envp);
}

void	second_child(int file1, int file2, int *end, char *cmd2, char **envp)
{
	char	**path_cmd;
	char	*cmd;

	path_cmd = split_path(envp);
	cmd = find_path(path_cmd, cmd2);
	dup2(end[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(end[1]);
	close(file1);
	execve(cmd, path_cmd, envp);
}
