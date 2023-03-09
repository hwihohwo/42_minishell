/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:58:06 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/12 19:59:45 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		index;
	char	*ret;

	index = 0;
	while (s[index])
		index++;
	ret = (char *)malloc(index * sizeof(char) + 1);
	if (ret == NULL)
		return (NULL);
	index = 0;
	while (s[index])
	{
		ret[index] = s[index];
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
