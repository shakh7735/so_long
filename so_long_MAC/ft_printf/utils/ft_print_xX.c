/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:28:48 by eshakhge          #+#    #+#             */
/*   Updated: 2022/04/03 14:47:25 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_begin_x(long nbr, t_flags *f, int size_str);

int	ft_print_xx(unsigned int nbr, t_flags *f)
{
	int		len;
	char	*temp;

	len = 0;
	if (f->point && !f->ttl && !nbr && !f->wdt)
		return (0);
	if (f->point && !f->ttl && !nbr && f->wdt)
	{
		len += ft_loop_putchar(' ', f->wdt);
		return (len);
	}
	if (f->ident == 'x')
		temp = ft_putnbr_base(nbr, "0123456789abcdef");
	else
		temp = ft_putnbr_base(nbr, "0123456789ABCDEF");
	len += ft_begin_x (nbr, f, ft_strlen(temp));
	len += ft_putstr(temp);
	if (f->minus)
		len += ft_loop_putchar(' ', f->wdt - len);
	free (temp);
	return (len);
}

static int	ft_begin_x(long nbr, t_flags *f, int size_str)
{
	int	lentgh;

	if (nbr == 0)
		f->resh = 0;
	if (f->point)
		f->ttl = f->ttl - size_str;
	if (f->ttl < 0)
		f->ttl = 0;
	lentgh = f->spc + size_str + f->ttl + f->resh;
	if (!f->minus && !f->zero)
		f->len += ft_loop_putchar(' ', f->wdt - lentgh);
	else if (!f->minus && f->point)
		f->len += ft_loop_putchar(' ', f->wdt - lentgh);
	if (f->spc)
		f->len += ft_putchar(' ');
	if (f->resh && f->ident == 'x')
		f->len += ft_putstr("0x");
	else if (f->resh && f->ident == 'X')
		f->len += ft_putstr("0X");
	if (!f->minus && !f->point && f->zero)
		f->len += ft_loop_putchar('0', f->wdt - lentgh);
	if (f->point)
		f->len += ft_loop_putchar('0', f->ttl);
	return (f->len);
}
