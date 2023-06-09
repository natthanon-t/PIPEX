/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:00:34 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/09 22:40:49 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

void	pipex(int file2, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		end[2];

	if (pipe(end) == -1)
		error("Pipe error");
	pid1 = fork();
	if (pid1 == -1)
		error("First fork error");
	if (pid1 == 0)
		first_child(argv, end, envp);
	pid2 = fork();
	if (pid2 == -1)
		error("Second fork error");
	if (pid2 == 0)
		second_child(file2, end, argv, envp);
	close(end[0]);
	close(end[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	file2;

	if (argc != 5)
		error("Input parameter error");
	file2 = open(argv[4], O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (file2 == -1)
		message_error("no such file or directory: ", argv[argc - 1], EXIT_FAILURE);
	pipex(file2, argv, envp);
	close(file2);
}
