/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:34:03 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/08 12:34:07 by jeongmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_cd(char *argv)
{
	char	**path;
	char	buffer[255];

	path = ft_split(argv, ' ');
	if (path == NULL)
	{
		ft_putendl_fd("malloc failed", 2);
		return (1);
	}
	if (chdir(path[1]) == -1)
	{
		ft_putendl_fd("chdir failed", 2);
		return (1);
	}
	ft_putendl_fd(getcwd(buffer, 255), 2); // 테스트용, 추후 지울 것
	return (0);
}