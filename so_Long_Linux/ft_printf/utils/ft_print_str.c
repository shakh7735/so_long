/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:17:13 by eshakhge          #+#    #+#             */
/*   Updated: 2022/04/03 14:20:29 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr_n(const char *s, int n);

int	ft_print_str(char *str, t_flags *f)
{
	int	len;
	int	size_str;

	len = 0;
	if (!str)
		str = "(null)";
	size_str = ft_strlen(str);
	if (f->point == 1 && size_str > f->ttl)
		size_str = f->ttl;
	if (f->minus == 1)
	{
		len += ft_putstr_n (str, size_str);
		len += ft_loop_putchar(' ', f->wdt - size_str);
	}
	else
	{
		len += ft_loop_putchar(' ', f->wdt - size_str);
		len += ft_putstr_n (str, size_str);
	}
	return (len);
}

static int	ft_putstr_n(const char *s, int n)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] && len < n)
		ft_putchar (s[len++]);
	return (len);
}
