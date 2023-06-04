/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:00:34 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/03 22:02:05 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include "libft/include/ft_printf.h"
#include "libft/include/libft.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int	status;
	int		end[2];
	int 	file1;
	int 	file2;

	if (argc != 5)
		return (1);
	file1 = open(argv[1], O_WRONLY);
	file2 = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (pipe(end) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid1 = fork();
	//if (pid1 == -1)
	//	return (perror("Fork1"));
	if (pid1 == 0)
		first_child(file1, file2, end, argv[2], envp);
	pid2 = fork();
	//if (pid2 == -1)
	//	return (perror("Fork2"));
	if (pid2 == 0)
		second_child(file1, file2, end, argv[3], envp);
	close(end[0]);
	close(end[1]);
	close(file1);
	close(file2);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}
