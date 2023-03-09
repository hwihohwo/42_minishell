/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:48:25 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/08 20:32:56 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_ast	*new_ast_node(char *order, char *argv)
{
	t_ast	*ast_node;

	ast_node = (t_ast *)malloc(sizeof(t_ast));
	ast_node->order = order;
	ast_node->argu = argv;
	ast_node->type = find_data_type(order);
	ast_node->left = NULL;
	ast_node->right = NULL;
	return (ast_node);
}
