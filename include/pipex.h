/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:02:04 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/03 21:35:20 by ntairatt         ###   ########.fr       */
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

char	**split_path(char **envp);
char	*find_path(char **path, char *cmd);
void	first_child(int file1, int file2, int *end, char *cmd1, char **envp);
void	second_child(int file1, int file2, int *end, char *cmd2, char **envp);

#endif
