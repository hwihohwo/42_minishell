/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:52:14 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/12 19:45:30 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*arr;

	arr = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (arr[index] == (unsigned char)c)
			return ((void *)(arr + index));
		index++;
	}
	return (0);
}
