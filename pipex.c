/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:00:34 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/04 15:24:54 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include "libft/include/ft_printf.h"
#include "libft/include/libft.h"

void	pipex(int file1, int file2, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		end[2];
	int		status;

	status = 0;
	if (pipe(end) == -1)
		return (perror("pipe"));
	pid1 = fork();
	if (pid1 == -1)
		return (perror("Fork1"));
	if (pid1 == 0)
		first_child(file1, end, full_cmd(argv[2], envp), envp);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("Fork2"));
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
		return (2);
	file1 = open(argv[1], O_WRONLY);
	file2 = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (file1 == -1 || file2 == -1)
		return (2);
	pipex(file1, file2, argv, envp);
	close(file1);
	close(file2);
	return (0);
}
