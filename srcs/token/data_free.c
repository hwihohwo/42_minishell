/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:39:35 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/11 18:06:30 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	token_data_free(t_tokendata *token_data)
{
	if (token_data != 0)
	{
		if (token_data->order != 0)
			free(token_data->order);
		if (token_data->argu != 0)
			free(token_data->argu);
		free(token_data);
	}
}

void	error_exit(char *str)
{
	perror(str);
	exit(1);
}
