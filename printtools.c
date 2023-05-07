/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fantures <fantures@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:45:18 by fantures          #+#    #+#             */
/*   Updated: 2023/05/04 15:23:33 by fantures         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, unsigned int *len)
{
	write(1, &c, 1);
	*(len) += 1;
}

void	ft_putstr(char *str, unsigned int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (str[i])
		ft_putchar(str[i++], len);
}

void	ft_putnbr(long n, unsigned int *len)
{
	if (n < 0)
	{
		ft_putchar('-', len);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr((n / 10), len);
		ft_putnbr((n % 10), len);
	}
	else
	{
		ft_putchar((n + 48), len);
	}
}

void	ft_putptr(unsigned long ptr, unsigned int *len)
{
	if (!ptr)
		ft_putstr("(nil)", len);
	else
	{
		ft_putstr("0x", len);
		ft_puthex(ptr, 0, len);
	}
}

void	ft_puthex(unsigned long nbr, const char var, unsigned int *len)
{
	if (nbr == 0)
	{
		ft_putchar ('0', len);
		return ;
	}
	if (nbr >= 16)
	{
		ft_puthex((nbr / 16), var, len);
		ft_puthex((nbr % 16), var, len);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar((nbr + 48), len);
		else if (var == 0 || var == 'x')
			ft_putchar(((nbr - 10) + 'a'), len);
		else if (var == 'X')
			ft_putchar(((nbr - 10) + 'A'), len);
	}
}
