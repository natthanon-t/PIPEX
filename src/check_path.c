/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:37:56 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/11 11:59:08 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_path(char **envp)
{
	char	*all_path;
	char	**path;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	all_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	path = ft_split(all_path, ':');
	free(all_path);
	return (path);
}

char	*find_path(char **path, char *cmd)
{
	char	**new_cmd;
	char	*path_test;
	char	*cmd_test;
	int		i;

	i = 0;
	new_cmd = ft_split(cmd, ' ');
	if (access(new_cmd[0], F_OK) == 0)
		return (new_cmd[0]);
	cmd_test = ft_strjoin("/", new_cmd[0]);
	while (path[i])
	{
		path_test = ft_strjoin(path[i++], cmd_test);
		if (access(path_test, F_OK) == 0)
		{
			free(cmd_test);
			free_2(new_cmd);
			return (path_test);
		}
		free(path_test);
	}
	free_2(new_cmd);
	free(cmd_test);
	if (ft_strchr(cmd, '/'))
		message_error("no such file or directory: ", cmd, 127);
	message_error("command not found: ", cmd, 127);
	return (NULL);
}

char	**full_cmd(char *cmd, char **envp)
{
	char	**path;
	char	**tmp_cmd;
	char	**new_cmd;
	char	*cmd_path;
	int		i;

	i = 0;
	tmp_cmd = ft_split(cmd, ' ');
	path = split_path(envp);
	cmd_path = find_path(path, tmp_cmd[i]);
	new_cmd = (char **)ft_calloc(ft_2dlen(tmp_cmd) + 1, sizeof(char *));
	if (!new_cmd)
		return (NULL);
	if (tmp_cmd[i])
	{
		new_cmd[i] = ft_strdup(cmd_path);
		while (tmp_cmd[++i])
			new_cmd[i] = ft_strdup(tmp_cmd[i]);
	}
	free(cmd_path);
	free_2(path);
	free_2(tmp_cmd);
	return (new_cmd);
}
