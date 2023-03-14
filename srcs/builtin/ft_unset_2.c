/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:43:25 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/14 19:44:06 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	delete_env(char **env)
{
	free(*env);
	env = 0;
}

int	env_num(char **env)
{
	int	count;

	count = 0;
	if (env == 0)
		return (0);
	while (env[count])
		count++;
	return (count);
}

int	env_new_num(char **env, int old_num)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < old_num)
	{
		if (env[i] == 0)
		{
			i++;
			continue ;
		}
		count++;
		i++;
	}
	return (count);
}
