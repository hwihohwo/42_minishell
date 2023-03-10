/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:04:22 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/13 14:28:07 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	if (argc != 1)
	{
		ft_printf("no arguments!\n");
		return (127);
	}
	argv = 0;
	readline(env);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	if (ac != 1)
		return (0);

	av = NULL;
	return (ft_readline(envp));
}