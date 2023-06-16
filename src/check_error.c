/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:36:36 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/16 18:01:05 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	message_error(char *str, char *var)
{
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(var, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	cmd_error(char *argv, char **cmd)
{
	cmd = ft_split(argv, ' ');
	if (ft_strrchr(cmd[0], '/'))
		message_error("no such file or directory: ", cmd[0]);
	else
		message_error("command not found: ", cmd[0]);
	free_2(cmd);
	exit(127);
}
