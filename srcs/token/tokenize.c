/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:21:56 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/08 19:56:24 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*input_string(char *line, int *i, int sav)
{
	int		j;
	char	*ret;

	j = 0;
	ret = ft_calloc(*i - sav + 1, sizeof(char));
	if (ret == 0)
		return (0);
	while (sav < *i)
		ret[j++] = line[sav++];
	return (ret);
}

t_tokendata	*new_tokendata(char	*line, int *i)
{
	int			sav;
	t_tokendata	*token_data;

	token_data = ft_calloc(1, sizeof(t_tokendata));
	if (token_data == 0)
		return (0);
	while (ft_isspace(line[*i]))
		(*i)++;
	sav = *i;
	if (line[*i] == '<' || line[*i] == '>')
		while ((line[*i] == '<' || line[*i] == '>') && line[*i])
			(*i)++;
	else
		while (!ft_isspace(line[*i]) && line[*i] && line[*i] != '|')
			(*i)++;
	if (line[*i] == '|' && sav == *i)
		(*i)++;
	token_data->order = input_string(line, i, sav);
	if (token_data->order == 0)
		return (0);
	if (token_data->order[0] == '|')
		return (token_data);
	return (tkdata_2(line, i, sav, token_data));
}

t_tokendata	*tkdata_2(char *line, int *i, int sav, t_tokendata *token_data)
{
	if (token_data->order[0] == '<' || token_data->order[0] == '>')
	{
		while (ft_isspace(line[*i]))
			(*i)++;
		while (!ft_isspecial(line[*i]) && line[*i] && !ft_isspace(line[*i]))
			(*i)++;
		token_data->argu = input_string(line, i, sav);
		if (token_data->argu == 0)
			return (0);
		return (token_data);
	}
	while (ft_isspace(line[*i]))
		(*i)++;
	while (!ft_isspecial(line[*i]) && line[*i])
		(*i)++;
	token_data->argu = input_string(line, i, sav);
	if (token_data->argu == 0)
		return (0);
	return (token_data);
}

t_tokenlist	*tokenize(char *line)
{
	char		*ret;
	int			i;
	t_tokendata	*token;
	t_tokenlist	*token_list;

	i = 0;
	token_list = 0;
	ret = first_line_setting(line);
	if (ret == 0)
		error_exit();
	while (ret[i])
	{
		token = new_tokendata(ret, &i);
		token->type = find_data_type(token->argu);
		if (token == 0)
			error_exit();
		tk_lstadd_back(&token_list, tk_lstnew(token));
	}
	free(ret);
	return (token_list);
}
