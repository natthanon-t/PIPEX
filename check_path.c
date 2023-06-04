/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:37:56 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/04 12:29:59 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include "libft/include/libft.h"

char	**split_path(char **envp)
{
	char	*path;

	path = ft_substr(envp[2], 5, ft_strlen(envp[2]));
	return (ft_split(path, ':'));
}

char	*find_path(char **path, char *cmd)
{
	char	**new_cmd;
	char	*path_test;
	char	*cmd_test;
	int		i;

	i = 0;
	new_cmd = ft_split(cmd, ' ');
	while (path[i])
	{
		cmd_test = ft_strjoin("/", new_cmd[0]);
		path_test = ft_strjoin(path[i++], cmd_test);
		if (access(path_test, 0) == 0)
			return (path_test);
		free(path_test);
		free(cmd_test);
	}
	return (NULL);
}

char	**full_cmd(char *cmd, char **envp)
{
	char	**path;
	char	**tmp_cmd;
	char	**new_cmd;
	char	*cmd_path;
	int		i;

	tmp_cmd = ft_split(cmd, ' ');
	path = split_path(envp);
	cmd_path = find_path(path, *tmp_cmd);
	i = sizeof(cmd_path) + sizeof(tmp_cmd);
	new_cmd = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!new_cmd)
		return (0);
	i = 0;
	while (tmp_cmd[i])
	{
		new_cmd[i] = cmd_path;
		while (tmp_cmd[++i])
			new_cmd[i] = tmp_cmd[i];
	}
	return (new_cmd);
}
