/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:12:19 by eshakhge          #+#    #+#             */
/*   Updated: 2022/04/03 13:31:05 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/ft_printf.h"

static int	ft_printf_loop(va_list args, t_flags *f, const char *str);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	*f;
	int		pr_len;

	f = malloc(sizeof(t_flags));
	if (!f)
		return (-1);
	va_start(args, str);
	pr_len = ft_printf_loop(args, f, str);
	va_end(args);
	free (f);
	return (pr_len);
}

static int	ft_printf_loop(va_list args, t_flags *f, const char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			f = ft_flags_init(f);
			if (ft_flags_search(f, str, i))
			{
				i = f->index;
				len += ft_print_args(args, f);
				i++;
			}
			else
				len += ft_putchar(str[i++]);
		}
		else
			len += ft_putchar(str[i++]);
	}
	return (len);
}

int	ft_flags_search(t_flags *f, const char *str, int index)
{
	f->index = index;
	while (ft_chek_specif(str[++index], "+-0 #"))
		ft_set_flags(f, str[index]);
	while (str[index] >= '0' && str[index] <= '9')
		f->wdt = f->wdt * 10 + (str[index++] - 48);
	if (ft_chek_specif(str[index], "."))
	{
		f->point = 1;
		while (str[++index] >= '0' && str[index] <= '9')
			f->ttl = f->ttl * 10 + (str[index] - 48);
	}
	f->ident = ft_chek_specif(str[index], "udpcsixX%");
	f->index = index;
	if (!f->ident)
		return (0);
	return (1);
}

char	ft_chek_specif(char c, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (c == str[i])
			return (c);
	return (0);
}

int	ft_print_args(va_list args, t_flags *f)
{
	int	len;

	len = 0;
	if (f->ident == 'c')
		len += ft_print_char (va_arg(args, unsigned int), f);
	else if (f->ident == 's')
		len += ft_print_str (va_arg(args, char *), f);
	else if (f->ident == 'p')
		len += ft_print_ptr (va_arg(args, unsigned long), f);
	else if (f->ident == 'd' || f->ident == 'i')
		len += ft_print_num (va_arg(args, int), f);
	else if (f->ident == 'u')
		len += ft_print_u (va_arg(args, unsigned int), f);
	else if (f->ident == 'x' || f->ident == 'X')
		len += ft_print_xx (va_arg(args, unsigned int), f);
	else if (f->ident == '%')
		len += ft_putchar ('%');
	return (len);
}
