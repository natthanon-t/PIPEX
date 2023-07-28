/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:37:56 by ntairatt          #+#    #+#             */
/*   Updated: 2023/07/28 22:54:57 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_path(char **envp, char **cmd)
{
	char	*all_path;
	char	**path;
	int		i;

	i = 0;
	if (!cmd)
		return (NULL);
	while (ft_strncmp(envp[i], "PATH", 4) != 0 && envp[i])
		i++;
	if (!envp[i])
	{
		message_error("No such file or directory", cmd[0]);
		free_2(cmd);
		exit(127);
	}
	all_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	if (!all_path)
		return (NULL);
	path = ft_split(all_path, ':');
	free(all_path);
	return (path);
}

char	*ft_findp(char **path, char *cmd_test, char **new_cmd)
{
	char	*path_test;
	int		i;

	i = 0;
	while (path[i])
	{
		path_test = ft_strjoin(path[i++], cmd_test);
		if (!path_test)
			return (NULL);
		if (access(path_test, X_OK) == 0)
		{
			free(cmd_test);
			free_2(new_cmd);
			return (path_test);
		}
		free(path_test);
	}
	return (NULL);
}

char	*find_path(char **path, char **cmd)
{
	char	**new_cmd;
	char	*cmd_test;
	char	*tmp_path;

	new_cmd = ft_split(cmd[0], ' ');
	if (!new_cmd)
		return (NULL);
	if (access(new_cmd[0], X_OK) == 0)
		return (new_cmd[0]);
	cmd_test = ft_strjoin("/", new_cmd[0]);
	if (!cmd_test)
	{
		free_2(new_cmd);
		return (NULL);
	}
	tmp_path = ft_findp(path, cmd_test, new_cmd);
	if (!tmp_path)
	{
		free_3(cmd_test, path, cmd);
		free_2(new_cmd);
		return (NULL);
	}
	return (tmp_path);
}

char	**make_cmd(t_pipex var, char **tmp_cmd)
{
	char	**new_cmd;
	int		i;

	new_cmd = (char **)ft_calloc(ft_2dlen(tmp_cmd) + 1, sizeof(char *));
	if (!new_cmd)
		return (NULL);
	i = 0;
	if (tmp_cmd[i])
	{
		new_cmd[i] = ft_strdup(var.cmd_path);
		if (!malloc_error(new_cmd, i))
			return (NULL);
		while (tmp_cmd[++i])
		{
			new_cmd[i] = ft_strdup(tmp_cmd[i]);
			if (!malloc_error(new_cmd, i))
				return (NULL);
		}
	}
	return (new_cmd);
}

char	**full_cmd(t_pipex var, char *cmd, char **envp)
{
	char	**tmp_cmd;
	char	**new_cmd;

	tmp_cmd = ft_split(cmd, ' ');
	var.path = split_path(envp, tmp_cmd);
	if (!var.path)
		return (NULL);
	var.cmd_path = find_path(var.path, tmp_cmd);
	if (!var.cmd_path)
		return (NULL);
	new_cmd = make_cmd(var, tmp_cmd);
	free_3(var.cmd_path, var.path, tmp_cmd);
	return (new_cmd);
}
