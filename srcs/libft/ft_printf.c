/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:04:00 by marvin            #+#    #+#             */
/*   Updated: 2023/01/04 12:28:56 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_specifier(char c, va_list *ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = case_c(va_arg(*ap, int));
	else if (c == 's')
		count = case_s(va_arg(*ap, char *));
	else if (c == 'p')
		count = case_p(va_arg(*ap, unsigned long));
	else if (c == 'd')
		count = case_d(va_arg(*ap, int));
	else if (c == 'i')
		count = case_d(va_arg(*ap, int));
	else if (c == 'u')
		count = case_u(va_arg(*ap, unsigned int));
	else if (c == 'x')
		count = case_x(va_arg(*ap, unsigned int));
	else if (c == 'X')
		count = case_upper_x(va_arg(*ap, unsigned int));
	else if (c == '%')
		count = case_percent();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += check_specifier(str[i], &ap);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
