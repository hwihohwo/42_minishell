/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:47:35 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/09 16:23:31 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_tree(t_ast **root)
{
	// 전위 순회 탐색
	// printf를 실행 함수로 바꾸면 전위 순회 탐색(및 실행)이 됨
	if (*root == NULL)
		return ;
	printf("%s : %s : %u\n", (*root)->order, (*root)->argu, (*root)->type);
	if (*root != NULL)
		print_tree(&(*root)->left);
	if (*root != NULL)
		print_tree(&(*root)->right);
}

enum e_token_type	find_data_type(char *argv)
{
	int	i;

	i = 0;
	if (argv == NULL)
		return (PIPE);
	else if (ft_strncmp(argv, "P", 1) == 0)
		return (PIPE);
	else if (ft_strncmp(argv, "<<", 2) == 0)
		return (HEREDOC);
	else if (ft_strncmp(argv, ">>", 2) == 0)
		return (APPEND);
	else if (ft_strncmp(argv, "<", 1) == 0)
		return (INPUT);
	else if (ft_strncmp(argv, ">", 1) == 0)
		return (OUTPUT);
	else if (ft_strncmp(argv, "T", 1) == 0)
		return (TREE);
	return (CMD);
}

void	ft_free_sp(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	redir_split(t_ast **node, t_tokenlist **token_node)
{
	char	*file_name;
	char	**tmp1;
	char	**tmp2;
	char	**tmp3;

	tmp1 = ft_split((*token_node)->data->argu, '<');
	tmp2 = ft_split(*tmp1, '>');
	tmp3 = ft_split(*tmp2, ' ');
	file_name = ft_strdup(tmp3[0]);

	ft_free_sp(tmp1);
	ft_free_sp(tmp2);
	ft_free_sp(tmp3);
	*node = new_ast_node((*token_node)->data->order, file_name);
}
