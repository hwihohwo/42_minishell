/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:04:22 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/13 18:19:43 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

char	**make_env_freeable(char **env)
{
	int		i;
	int		count;
	char	**temp;

	i = 0;
	count = 0;
	while (env[count])
		count++;
	temp = (char **)ft_calloc(count + 1, sizeof(char *));
	if (temp == 0)
		error_exit(0);
	while (i < count)
	{
		temp[i] = ft_strdup(env[i]);
		i++;
	}
	temp[i] = (char *)0;
	return (temp);
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 1)
	{
		ft_printf("no arguments!\n");
		return (127);
	}
	argv = 0;
	env = make_env_freeable(env);
	readline_start(env);
	return (0);
}
