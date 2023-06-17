/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:36:36 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/16 22:40:58 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcolon(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ':' && str[i + 1] == ' ')
			return (0);
		i++;
	}
	return (1);
}

void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	message_error(char *str, char *var)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(str);
	while (tmp[i])
	{
		if (tmp[i] >= 'A' && tmp[i] <= 'Z')
			tmp[i] += 32;
		i++;
	}
	ft_putstr_fd(tmp, STDERR_FILENO);
	if (ft_strcolon(tmp))
		ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(var, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	free(tmp);
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
