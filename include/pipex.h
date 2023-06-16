/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:02:04 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/16 17:48:52 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft.h"

char	**split_path(char **envp, char **cmd);
char	*find_path(char **path, char *cmd);
void	first_child(char **argv, int *end, char **envp);
void	second_child(int *end, char **argv, char **envp);
void	free_2(char **str);
char	**full_cmd(char *cmd, char **envp);
int		ft_2dlen(char **str);
void	error(char *str);
void	message_error(char *str, char *var);
void	cmd_error(char *argv, char **cmd);

#endif
