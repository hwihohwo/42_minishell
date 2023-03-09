/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:59:17 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/28 15:51:50 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t	i;
	size_t	len;

	if (*find == 0)
		return ((char *)str);
	i = 0;
	len = ft_strlen(find);
	while (str[i] && i < n)
	{
		if (i + len > n)
			return (NULL);
		if (str[i] == find[0])
		{
			if (ft_strncmp(&str[i], find, len) == 0)
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
