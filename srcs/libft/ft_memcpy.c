/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:34:08 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/13 15:07:09 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*temp1;
	unsigned char	*temp2;

	if (dst == NULL && src == NULL)
		return (dst);
	index = 0;
	temp1 = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	while (index < n)
	{
		temp1[index] = temp2[index];
		index++;
	}
	return (dst);
}
