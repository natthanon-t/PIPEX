/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:55:42 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/04 12:27:16 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include "libft/include/libft.h"

void	first_child(int file1, int *end, char *cmd1, char **envp)
{
	char	**path;
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split(cmd1, ' ');
	path = split_path(envp);
	cmd_path = find_path(path, cmd1);
	cmd[0] = cmd_path;
	/*for (int i =0;path[i];i++)
		printf("path[%d] = %s\n", i, path[i]);
	printf("cmd_path = %s\n", cmd_path);
	for (int i =0;cmd[i];i++)
		printf("cmd[%d] = %s\n", i, cmd[i]);*/
	dup2(file1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	if (execve(cmd_path, cmd, envp) == -1)
		perror("execve of first child");
	free_2(path);
	free_2(cmd);
	free(cmd_path);
}

void	second_child(int file2, int *end, char *cmd2, char **envp)
{
	char	**path;
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split(cmd2, ' ');
	path = split_path(envp);
	cmd_path = find_path(path, cmd2);
	cmd[0] = cmd_path;
	dup2(end[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(end[1]);
	if (execve(cmd_path, cmd, envp) == -1)
		perror("execve of second child");
	free_2(path);
	free_2(cmd);
	free(cmd_path);
}
