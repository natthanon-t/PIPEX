/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:36:36 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/16 14:57:37 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	message_error(char *str, char *var)
{
	write(2, str, ft_strlen(str));
	write(2, var, ft_strlen(var));
	write(2, "\n", 1);
}

void	cmd_error(char *argv, char **cmd)
{
	cmd = ft_split(argv, ' ');
	if (ft_strrchr(cmd[0], '/'))
		message_error("no such file or directory:", cmd[0]);
	else
		message_error("command not found: %s\n", cmd[0]);
	free_2(cmd);
	exit(127);
}
