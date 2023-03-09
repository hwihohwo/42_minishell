/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:49:14 by marvin            #+#    #+#             */
/*   Updated: 2023/01/04 12:42:43 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	calc_length(int base, unsigned long num)
{
	int	length;

	length = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base;
		length++;
	}
	return (length);
}

void	put_nbr_printf(long num, int base)
{
	long	temp;
	char	*base_list;

	temp = num;
	base_list = "0123456789abcdef";
	if (temp < 0)
	{
		write(1, "-", 1);
		temp *= -1;
	}
	if (temp / base > 0)
		put_nbr_printf(temp / base, base);
	write(1, &base_list[temp % base], 1);
}

void	put_nbr_printf_upper(long num, int base)
{
	long	temp;
	char	*base_list;

	temp = num;
	base_list = "0123456789ABCDEF";
	if (temp < 0)
	{
		write(1, "-", 1);
		temp *= -1;
	}
	if (temp / base > 0)
		put_nbr_printf_upper(temp / base, base);
	write(1, &base_list[temp % base], 1);
}

void	put_nbr_printf_p(unsigned long num, int base)
{
	unsigned long	temp;
	char			*base_list;

	temp = num;
	base_list = "0123456789abcdef";
	if (temp / base > 0)
		put_nbr_printf_p(temp / base, base);
	write(1, &base_list[temp % base], 1);
}
