/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:12:00 by eshakhge          #+#    #+#             */
/*   Updated: 2022/04/03 14:16:22 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long nbr, t_flags *f)
{
	int		len;
	char	*temp;
	int		size_str;

	len = 0;
	temp = ft_putnbr_base(nbr, "0123456789abcdef");
	size_str = ft_strlen(temp);
	if (!f->minus && f->ttl)
		len += ft_loop_putchar(' ', f->wdt
				- size_str - f->plus - 2 -(f->ttl - size_str));
	else if (!f->minus)
		len += ft_loop_putchar(' ', f->wdt - size_str - f->plus - 2);
	if (f->plus && nbr != 0)
		len += ft_putchar('+');
	if (f->spc && !f->plus)
		len += ft_putchar(' ');
	len += ft_putstr("0x");
	if (f->point && nbr != 0)
		len += ft_loop_putchar('0', f->ttl - size_str);
	len += ft_putstr(temp);
	size_str = len;
	if (f->minus)
		len += ft_loop_putchar(' ', f->wdt - size_str);
	free (temp);
	return (len);
}
