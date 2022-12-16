/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:47:54 by eshakhge          #+#    #+#             */
/*   Updated: 2022/04/03 14:52:13 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		ft_putchar (s[len++]);
	return (len);
}

t_flags	*ft_flags_init(t_flags *f)
{
	f->minus = 0;
	f->plus = 0;
	f->zero = 0;
	f->point = 0;
	f->spc = 0;
	f->resh = 0;
	f->index = 0;
	f->wdt = 0;
	f->ttl = 0;
	f->ident = 0;
	f->pref_minus = 0;
	f->len = 0;
	return (f);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_set_flags(t_flags *f, char c)
{
	if (c == '+')
		f->plus = 1;
	if (c == '-')
		f->minus = 1;
	if (c == ' ')
		f->spc = 1;
	if (c == '#')
		f->resh = 2;
	if (c == '0')
		f->zero = 1;
}
