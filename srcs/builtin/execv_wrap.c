/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execv_wrap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:31:30 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/13 18:07:42 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execve_free(char *order_full, char **argu_ary)
{
	int	i;

	i = 0;
	free(order_full);
	while (argu_ary[i])
		free(argu_ary[i++]);
	free(argu_ary);
}

int	execute_order(char *order, char *argu, char **env)
{
	char	*order_prefix;
	pid_t	pid;
	char	**argu_ary;
	char	*order_full;

	argu_ary = ft_split(argu, ' ');
	if (argu_ary == 0)
		error_exit(0);
	order_prefix = "./";
	order_full = ft_strjoin(order_prefix, order);
	if (order_full == 0)
		error_exit(0);
	if (execve(order_full, argu_ary, env) == -1)
	{
		order_prefix = "/bin/";
		free(order_full);
		order_full = ft_strjoin(order_prefix, order);
		if (order_full == 0)
			error_exit(0);
		if (execve(order_full, argu_ary, env) == -1)
			error_exit(0);
	}
	execve_free(order_full, argu_ary);
	return (0);
}
