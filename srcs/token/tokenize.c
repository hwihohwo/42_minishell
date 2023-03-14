/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:21:56 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/14 19:14:07 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tokendata	*new_tokendata(char	*line, int *i, t_tokenlist **token_list)
{
	t_indexinfo	info;
	t_tokendata	*token_data;

	token_data = ft_calloc(1, sizeof(t_tokendata));
	if (token_data == 0)
		return (0);
	while (ft_isspace(line[*i]))
		(*i)++;
	info.i = i;
	info.sav = *i;
	if (line[*i] == '<' || line[*i] == '>')
		while ((line[*i] == '<' || line[*i] == '>') && line[*i])
			(*i)++;
	else
		while (!ft_isspace(line[*i]) && line[*i] && line[*i] != '|')
			(*i)++;
	if (line[*i] == '|' && info.sav == *i)
		(*i)++;
	token_data->order = input_string(line, i, info.sav);
	if (token_data->order[0] == '|')
		return (token_data);
	return (tkdata_2(line, &info, token_data, token_list));
}

t_tokendata	*tkdata_2(char *line, t_indexinfo *info, t_tokendata *token_data, \
t_tokenlist **token_list)
{
	if (token_data->order[0] == '<' || token_data->order[0] == '>')
	{
		while (ft_isspace(line[*(info->i)]))
			(*(info->i))++;
		while (!ft_isspecial(line[*(info->i)]) && line[*(info->i)] \
		&& !ft_isspace(line[*(info->i)]))
			(*(info->i))++;
		token_data->argu = input_string(line, info->i, info->sav);
		return (token_data);
	}
	while (ft_isspace(line[*(info->i)]))
		(*(info->i))++;
	while (line[*(info->i)] != '|' && line[*(info->i)])
	{
		if (line[*(info->i)] == '>' || line[*(info->i)] == '<')
		{
			case_middle_redir(line, info->i, token_list);
			continue ;
		}
		(*(info->i))++;
	}
	token_data->argu = input_string(line, info->i, info->sav);
	return (token_data);
}

void	case_middle_redir(char *line, int *i, t_tokenlist **token_list)
{
	t_tokendata	*token_data;
	int			sav;

	token_data = ft_calloc(1, sizeof(t_tokendata));
	if (token_data == 0)
		error_exit(0);
	sav = *i;
	if (line[*i] == '<' || line[*i] == '>')
		while ((line[*i] == '<' || line[*i] == '>') && line[*i])
			(*i)++;
	token_data->order = input_string(line, i, sav);
	while (ft_isspace(line[*i]))
			(*i)++;
	while (!ft_isspecial(line[*i]) && line[*i] && !ft_isspace(line[*i]))
			(*i)++;
	token_data->argu = input_string(line, i, sav);
	token_data->type = find_data_type(token_data->argu);
	tk_lstadd_back(token_list, tk_lstnew(token_data));
}

t_tokenlist	*tokenize(char *line, char **env)
{
	char		*ret;
	int			i;
	t_tokendata	*token;
	t_tokenlist	*token_list;

	i = 0;
	token_list = 0;
	ret = first_line_setting(line, env);
	while (ret[i])
	{
		token = new_tokendata(ret, &i, &token_list);
		if (token == 0)
			error_exit(0);
		token->type = find_data_type(token->argu);
		tk_lstadd_back(&token_list, tk_lstnew(token));
	}
	free(ret);
	return (token_list);
}
