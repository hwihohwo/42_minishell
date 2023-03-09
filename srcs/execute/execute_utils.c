/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:21:35 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/09 18:21:38 by jeongmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_fd	*init_fd_struct(t_ast *tree_node)
{
	t_fd	*fd_data;
	int		i;

	fd_data = (t_fd *)malloc(sizeof(t_fd));
	if (fd_data == NULL)
		exit(1);
	fd_data->pipe_cnt = count_pipe(tree_node);
	fd_data->fd = (int *)malloc(sizeof(int) * fd_data->pipe_cnt);
	fd_data->fd_input = 0;
	fd_data->fd_input = 1;
	fd_data->fd_flag = 0; // input, output .. 등 일 때 open 한 값을 추가로 저장 
	if (fd_data->fd == NULL)
		exit(1);
	fd_data->idx = 0;
	i = 0;
	while (i < fd_data->pipe_cnt)
	{
		if (pipe(fd_data->fd + (2 * i)) == -1)
		{
			free(fd_data->fd);
			exit(1);
		}
		i++;
	}
	return (fd_data);
}

int	count_pipe(t_ast *node)
{
	int	cnt;

	cnt = 0;
	while (node->right)
	{
		if (node->type == PIPE)
			cnt++;
		node = node->right;
	}
	return (cnt);
}
