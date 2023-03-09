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

void	execute(t_ast *node)
{

}

void	preorder_traversal(t_ast **root)
{
	if (*root == NULL)
		return ;
	exec_command(*root);
	if (*root != NULL)
		preorder_traversal(&(*root)->left);
	if (*root != NULL)
		preorder_traversal(&(*root)->right);
}

int	exec_command(t_ast *node)
{
	int	flag;

	if (ft_strncmp(node->order, "cd", 2) == 0)
		ft_cd(node->argu);
	else if (ft_strncmp(node->order, "echo", 4) == 0)
		return (0);
	else if (ft_strncmp(node->order, "pwd", 3) == 0)
		return (0);
	else if (ft_strncmp(node->order, "env", 3) == 0)
		return (0);
	else if (ft_strncmp(node->order, "export", 6) == 0)
		return (0);
	else if (ft_strncmp(node->order, "unset", 5) == 0)
		return (0);
	else if (ft_strncmp(node->order, "exit", 4) == 0)
		return (0);
	else

	// 전위 순회 탐색으로 돌면서 order가 cd 라면 ft_cd
	// echo 라면 ft_echo 작동 ...
	flag = 1; // command is not found
	// execve 함수를 다음처럼 이용해야 되나?
	// execve("srcs/builtin/명령어", **argv, envp);
	return (flag);
}
