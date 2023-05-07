/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fantures <fantures@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:13:24 by fantures          #+#    #+#             */
/*   Updated: 2023/05/04 15:25:40 by fantures         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	ft_printer(va_list arg, const char var, unsigned int *len);
void	ft_putchar(int c, unsigned int *len);
void	ft_putstr(char *str, unsigned int *len);
void	ft_putnbr(long n, unsigned int *len);
void	ft_putptr(unsigned long ptr, unsigned int *len);
void	ft_puthex(unsigned long nbr, const char var, unsigned int *len);

#endif
