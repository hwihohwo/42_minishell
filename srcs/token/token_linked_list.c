/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_linked_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:46:19 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/08 19:21:45 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tk_lstadd_back(t_tokenlist **lst, t_tokenlist *new)
{
	t_tokenlist	*temp;

	if (lst == NULL || new == NULL)
		return ;
	temp = *lst;
	if (temp == NULL)
		*lst = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

t_tokenlist	*tk_lstnew(t_tokendata *content)
{
	t_tokenlist	*node;

	node = (t_tokenlist *)malloc(sizeof(t_tokenlist));
	if (node == NULL)
		return (NULL);
	node->data = content;
	node->next = NULL;
	return (node);
}

void	tk_lstclear(t_tokenlist **lst, void (*del)(t_tokendata *))
{
	t_tokenlist	*temp;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->data);
		free(*lst);
		*lst = temp;
	}
}

void	tk_lstiter(t_tokenlist *lst, void (*f)(t_tokendata *))
{
	if (lst == NULL)
		return ;
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
	}
}
