/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:47:14 by marvin            #+#    #+#             */
/*   Updated: 2023/01/04 12:29:00 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		check_specifier(char c, va_list *ap);
void	put_nbr_printf(long num, int base);
void	put_nbr_printf_upper(long num, int base);
int		case_c(char c);
int		case_s(char *str);
int		case_p(unsigned long ptr);
int		case_d(int num);
int		case_u(unsigned int num);
int		case_x(unsigned int num);
int		case_upper_x(unsigned int num);
int		case_percent(void);
void	put_nbr_printf_p(unsigned long num, int base);
int		calc_length(int base, unsigned long num);

#endif