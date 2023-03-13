/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:14:29 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/07 19:14:31 by jeongmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		pipe_check(t_ast *node, t_fd *fd_data);

void	execute(t_ast *node, char **envp)
{
	t_fd	*fd_data;

	fd_data = init_fd_struct(envp);
	count_pipe(node, fd_data);
	if (pipe_check(node, fd_data) == 0)
		ft_putendl_fd("syntax error near unexpected token `|'", 2);
	else
	{
		preorder_traversal(node, fd_data);
		while (fd_data->pipe_cnt--)
			wait(NULL);
	}
	execute_free(node, fd_data);
//	sleep(10);
}

t_fd	*init_fd_struct(char **envp)
{
	t_fd	*fd_data;

	fd_data = (t_fd *)malloc(sizeof(t_fd));
	if (fd_data == NULL)
		exit(1);
	fd_data->envp = envp;
	fd_data->fd_read = STDIN_FILENO;
	fd_data->fd_write = STDOUT_FILENO;
	fd_data->pipe_read = STDIN_FILENO;
	fd_data->pipe_write = STDOUT_FILENO;
	fd_data->pipe_cnt = 0;
	fd_data->pipe_idx = -1;
	fd_data->fd_flag = 0; // input, output .. 등 일 때 open 한 값을 추가로 저장 
	return (fd_data);
}

int	pipe_check(t_ast *node, t_fd *fd_data)
{
	int	i;

	if (fd_data->pipe_cnt > 1)
	{
		i = 0;
		while (i < fd_data->pipe_cnt)
		{
			if (node->left == NULL)
				return (0);
			node = node->right;
			i++;
		}
	}
	return (1);
}

void	preorder_traversal(t_ast *root, t_fd *fd_data)
{
	execute_node(root, fd_data);
	if (root->left != NULL)
		preorder_traversal(root->left, fd_data);
	if (root->right != NULL)
		preorder_traversal(root->right, fd_data);
}
