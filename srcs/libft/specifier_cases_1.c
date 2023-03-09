/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_cases_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:42:25 by marvin            #+#    #+#             */
/*   Updated: 2023/01/04 12:40:05 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_c(char c)
{
	return (write(1, &c, 1));
}

int	case_s(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == 0)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i++], 1);
		count++;
	}
	return (count);
}

int	case_p(unsigned long ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += calc_length(16, ptr);
	put_nbr_printf_p(ptr, 16);
	return (count);
}

int	case_d(int num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count++;
		if (num == -2147483648)
			count += 10;
		else
			count += calc_length(10, -num);
	}
	else
		count += calc_length(10, num);
	put_nbr_printf(num, 10);
	return (count);
}

int	case_u(unsigned int num)
{
	int	count;

	count = 0;
	count += calc_length(10, num);
	put_nbr_printf(num, 10);
	return (count);
}
