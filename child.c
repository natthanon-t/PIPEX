/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:55:42 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/06 14:53:04 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	first_child(int file1, int *end, char **cmd, char **envp)
{
	dup2(file1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
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
