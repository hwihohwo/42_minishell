/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:15:51 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/14 20:16:59 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(void)
{
	char	*buffer;

	buffer = 0;
	buffer = getcwd(buffer, 0);
	ft_printf("%s\n", buffer);
	free(buffer);
	return (0);
}
