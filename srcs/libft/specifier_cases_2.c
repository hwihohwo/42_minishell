/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_cases_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:24:38 by marvin            #+#    #+#             */
/*   Updated: 2023/01/04 12:18:42 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_x(unsigned int num)
{
	int	count;

	count = 0;
	count += calc_length(16, num);
	put_nbr_printf(num, 16);
	return (count);
}

int	case_upper_x(unsigned int num)
{
	int	count;

	count = 0;
	count += calc_length(16, num);
	put_nbr_printf_upper(num, 16);
	return (count);
}

int	case_percent(void)
{
	char	percent;

	percent = '%';
	write(1, &percent, 1);
	return (1);
}
