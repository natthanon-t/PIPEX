/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:00:34 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/06 22:33:34 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

void	pipex(int file1, int file2, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		end[2];
	int		status;

	status = 0;
	if (pipe(end) == -1)
		error("Pipe error");
	pid1 = fork();
	if (pid1 == -1)
		error("First fork error");
	if (pid1 == 0)
		first_child(file1, end, full_cmd(argv[2], envp), envp);
	pid2 = fork();
	if (pid2 == -1)
		error("Second fork error");
	if (pid2 == 0)
		second_child(file2, end, full_cmd(argv[3], envp), envp);
	close(end[0]);
	close(end[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	end[2];
	int	file1;
	int	file2;

	if (argc != 5)
		error("Input parameter error");
	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[4], O_TRUNC | O_WRONLY | O_CREAT, 0777);
	if (file1 == -1)
		message_error("no such file or directory: ", argv[1]);
	if (file2 == -1)
		message_error("no such file or directory: ", argv[4]);
	pipex(file1, file2, argv, envp);
	close(file1);
	close(file2);
	return (0);
}
