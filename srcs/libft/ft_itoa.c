/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:50:42 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/28 20:04:09 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*exception(void)
{
	char	*ret;

	ret = (char *)malloc(2);
	if (ret == NULL)
		return (NULL);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

char	*ft_itoa(int n)
{
	long long	temp;
	int			len;
	char		*ret;

	temp = n;
	if (n == 0)
		return (exception());
	len = length(temp);
	ret = (char *)malloc(len * sizeof(char) + 1);
	if (ret == NULL)
		return (NULL);
	if (temp < 0)
	{
		temp *= -1;
		ret[0] = '-';
	}
	ret[len--] = '\0';
	while (temp != 0)
	{
		ret[len--] = temp % 10 + '0';
		temp /= 10;
	}
	return (ret);
}
