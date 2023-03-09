/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:55:20 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/12 15:56:11 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int n)
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

static void	exception(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else
		write(fd, "-2147483648", 11);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		len;
	char	ans[50];

	if (fd < 0)
		return ;
	if (n == -2147483648 || n == 0)
	{
		exception(n, fd);
		return ;
	}
	len = length(n);
	i = len;
	if (n < 0)
	{
		n *= -1;
		ans[0] = '-';
	}
	ans[len--] = '\0';
	while (n != 0)
	{
		ans[len--] = n % 10 + '0';
		n /= 10;
	}
	write(fd, ans, i);
}
