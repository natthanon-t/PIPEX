/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:36:36 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/15 13:23:20 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	message_error(char *str, char *var, int nbr)
{
	ft_printf("%s", str);
	ft_printf("%s\n", var);
	exit(nbr);
}
