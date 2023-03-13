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
