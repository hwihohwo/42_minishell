/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:55:59 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/08 19:50:37 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_ast	*syntax_analyzer(t_tokenlist *token_node)
{
	t_ast	*root;

	root = NULL;
	syntax_pipe(&root, &token_node);
	return (root);
}

// t_ast	*token_parse(char **argv)
// {
// 	t_tokenlist	*token_list;
// 	t_ast		*ast_root;

// 	token_list = tokenize(argv); // 토큰 연결리스트 생성
// //	check_token(token_root); // 토큰 연결리스트 확인용
// 	ast_root = syntax_analyzer(token_list); // lexer : ast 생성, 반환 값은 오류 코드
// //	print_tree(&ast_root);

// 	return (ast_root);
// }
