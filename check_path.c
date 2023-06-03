/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:37:56 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/03 18:37:03 by ntairatt         ###   ########.fr       */
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
	char	*path_test;
	char	*cmd_test;
	int		i;

	i = 0;
	while (path[i])
	{
		cmd_test = ft_strjoin("/", cmd);
		path_test = ft_strjoin(path[i], cmd_test);
		if (access(path_test, 0) == 0)
			return (path_test);
		free(path_test);
		free(cmd_test);
		i++;
	}
	return (NULL);
} 
