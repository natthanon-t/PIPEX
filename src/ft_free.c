/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:02:10 by ntairatt          #+#    #+#             */
/*   Updated: 2023/07/28 16:21:48 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	ft_2dlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_3(char *cmd_path, char **path, char **tmp_cmd)
{
	if (cmd_path)
		free(cmd_path);
	if (path)
		free_2(path);
	if (tmp_cmd)
		free_2(tmp_cmd);
}

int	malloc_error(char **new_cmd, int i)
{
	if (!new_cmd)
		return (0);
	else if (!new_cmd[i])
	{
		free_2(new_cmd);
		return (0);
	}
	else
		return (1);
}
