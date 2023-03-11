/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execv_wrap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:31:30 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/11 18:16:38 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_order(char *order, char *argu, char **env)
{
	char	*order_prefix;
	pid_t	pid;
	char	**argu_ary;

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
}
