/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:18:20 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/13 14:27:31 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	syntax_pipe(t_ast **root, t_tokenlist **token_node)
{
	// 파이프 단독으로 들어오거나 끝이 파이프로 끝나는 경우 &(*token_node)->next == NULL 인 경우
	// 시작할 때 체크하지 않으면 (*token_node)->type 을 확인할 때 터짐
//	if (*token_node == NULL)
//		return ;
	if (*root == NULL)
		*root = new_ast_node("P", "PIPE"); // T = tree_node
	if ((*token_node) == NULL)
		return ;
	if ((*token_node)->data->type != PIPE)
		syntax_cmd(&(*root)->left, token_node);
	// syntax_cmd 에서 null 확인후 돌려받았을때 종료
	if (*token_node == NULL)
		return ;
	if ((*token_node)->data->type == PIPE)
		syntax_pipe(&(*root)->right, &(*token_node)->next);
}

void	syntax_cmd(t_ast **node, t_tokenlist **token_node)
{
//	if ((*token_node) == NULL)
//		return ;
	if (*node == NULL)
		*node = new_ast_node("C", "CMD");
	if ((*token_node)->data->type == SCMD || (*token_node)->data->type == CMD)
		syntax_simple_cmd(&(*node)->right, token_node);
	// syntax_simple_cmd 에서 *token_node->next 값이 null인지 확인 
	if (*token_node == NULL)
		return ;
	if ((*token_node)->data->type == INPUT || (*token_node)->data->type == OUTPUT || \
	(*token_node)->data->type == HEREDOC || (*token_node)->data->type == APPEND)
		syntax_redir(&(*node)->left, token_node);
	if ((*token_node) == NULL)
		return ;
	if ((*token_node)->data->type == CMD || (*token_node)->data->type == SCMD)
		syntax_simple_cmd(&(*node)->right, token_node);
	// CMD 는 REDIR과 달리 복수 개의 명령어 인자가 들어와도 하나로 인식하기 때문에 REDIR처럼 가지치기 할 필요가 없음
}

void	syntax_redir(t_ast **node, t_tokenlist **token_node)
{
	if ((*token_node) == NULL)
		return ;
	if (*node == NULL)
		*node = new_ast_node("R", "REDIRS");
	syntax_simple_redir(&(*node)->left, token_node);
	// syntax_simple_redir 에서 *token_node_next 값이 null인지 확인
	if (*token_node == NULL)
		return ;
	if ((*token_node)->data->type == INPUT || (*token_node)->data->type == OUTPUT || \
	(*token_node)->data->type == HEREDOC || (*token_node)->data->type == APPEND)
		syntax_redir(&(*node)->right, token_node);
//	else if ((*token_node)->data->type == CMD || (*token_node)->data->type == SCMD)
//		syntax_cmd(&(*node)->left, token_node);
}

void	syntax_simple_redir(t_ast **node, t_tokenlist **token_node)
{
	if (*node == NULL)
		redir_split(node, token_node);
	*token_node = (*token_node)->next;
}

void	syntax_simple_cmd(t_ast **node, t_tokenlist **token_node)
{
	if (*node == NULL)
		*node = new_ast_node("S", "SCMD");
	(*node)->left = new_ast_node((*token_node)->data->order, (*token_node)->data->argu);
	*token_node = (*token_node)->next;
	if ((*token_node) != NULL)
	{
		if((*token_node)->data->type == SCMD)
			syntax_simple_cmd(&(*node)->right, token_node);
	}
}
