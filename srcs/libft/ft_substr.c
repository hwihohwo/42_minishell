/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:59:45 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/28 18:46:22 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*exception(char *ret)
{
	ret = malloc(1);
	if (ret == NULL)
		return (NULL);
	ret[0] = 0;
	return (ret);
}

char	*allocation(char const *s, unsigned int start, size_t len, char *ret)
{
	if (start + len > ft_strlen(s))
	{
		ret = (char *)malloc(ft_strlen(s) - start + 1);
		if (ret == NULL)
			return (NULL);
	}
	else
	{
		ret = (char *)malloc(len + 1);
		if (ret == NULL)
			return (NULL);
	}
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	index;
	size_t	index2;

	ret = NULL;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (exception(ret));
	index2 = start;
	ret = allocation(s, start, len, ret);
	if (ret == NULL)
		return (NULL);
	index = 0;
	while (s[index2] && index < len)
		ret[index++] = s[index2++];
	ret[index] = '\0';
	return (ret);
}
