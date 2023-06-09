/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:36:36 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/09 22:13:44 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

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
