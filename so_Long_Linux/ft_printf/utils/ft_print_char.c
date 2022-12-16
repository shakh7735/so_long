/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:31:27 by eshakhge          #+#    #+#             */
/*   Updated: 2022/04/03 13:35:55 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, t_flags *f)
{
	int	len;

	len = 0;
	if (f->minus == 1)
	{
		len += ft_putchar(c);
		len += ft_loop_putchar(' ', f->wdt - 1);
	}
	else
	{
		len += ft_loop_putchar(' ', f->wdt - 1);
		len += ft_putchar(c);
	}
	return (len);
}

int	ft_loop_putchar(char c, int size)
{
	int	i;

	i = 0;
	while (i++ < size)
		ft_putchar(c);
	return (--i);
}
