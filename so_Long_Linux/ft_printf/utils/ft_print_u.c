/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:21:07 by eshakhge          #+#    #+#             */
/*   Updated: 2022/04/03 14:24:50 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_begin_u(long nbr, t_flags *f, int size_str);

int	ft_print_u(unsigned int nbr, t_flags *f)
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
	temp = ft_putnbr_base(nbr, "0123456789");
	len += ft_begin_u (nbr, f, ft_strlen(temp));
	len += ft_putstr(temp);
	if (f->minus)
		len += ft_loop_putchar(' ', f->wdt - len);
	free (temp);
	return (len);
}

static int	ft_begin_u(long nbr, t_flags *f, int size_str)
{
	int	lentgh;

	if (f->plus)
		f->spc = 0;
	if (f->point)
		f->ttl = f->ttl - size_str;
	if (f->ttl < 0)
		f->ttl = 0;
	lentgh = f->plus + f->pref_minus + f->spc + size_str + f->ttl;
	if (!f->minus && !f->zero)
		f->len += ft_loop_putchar(' ', f->wdt - lentgh);
	else if (!f->minus && f->point)
		f->len += ft_loop_putchar(' ', f->wdt - lentgh);
	if (f->plus && nbr >= 0)
		f->len += ft_putchar('+');
	if (nbr < 0)
		f->len += ft_putchar('-');
	if (f->spc && nbr >= 0)
		f->len += ft_putchar(' ');
	if (!f->minus && !f->point && f->zero)
		f->len += ft_loop_putchar('0', f->wdt - lentgh);
	if (f->point)
		f->len += ft_loop_putchar('0', f->ttl);
	return (f->len);
}
