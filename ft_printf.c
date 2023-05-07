/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fantures <fantures@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:04:41 by fantures          #+#    #+#             */
/*   Updated: 2023/05/04 15:15:01 by fantures         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printer(va_list arg, const char var, unsigned int *len)
{
	if (var == 'c')
		ft_putchar(va_arg(arg, int), len);
	else if (var == 's')
		ft_putstr(va_arg(arg, char *), len);
	else if (var == 'p')
		ft_putptr(va_arg(arg, unsigned long long), len);
	else if (var == 'd' || var == 'i')
		ft_putnbr(va_arg(arg, int), len);
	else if (var == 'u')
		ft_putnbr(va_arg(arg, unsigned int), len);
	else if (var == 'x' || var == 'X')
		ft_puthex(va_arg(arg, unsigned int), var, len);
	else if (var == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	int				i;
	unsigned int	fullen;
	va_list			arg;

	i = 0;
	fullen = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_printer(arg, str[i + 1], &fullen);
			i++;
		}
		else
			ft_putchar(str[i], &fullen);
		i++;
	}
	va_end(arg);
	return (fullen);
}
