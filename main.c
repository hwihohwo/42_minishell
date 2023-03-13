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
	readline_start(env);
	return (0);
}
