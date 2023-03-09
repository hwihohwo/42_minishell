/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:46:29 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/13 15:27:29 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*arr1;
	unsigned char	*arr2;

	arr1 = (unsigned char *)dst;
	arr2 = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src && dst < src + n)
	{
		while (n)
		{
			n--;
			arr1[n] = arr2[n];
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, n));
}
