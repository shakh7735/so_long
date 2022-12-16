/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:55:20 by eshakhge          #+#    #+#             */
/*   Updated: 2022/04/03 14:56:50 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*print_ch(unsigned long nbr, char *base, int n);
static int	check_base(int ba, char *base);

char	*ft_putnbr_base(unsigned long nbr, char *base)
{
	int	ba;

	ba = 0;
	ba = check_base(ba, base);
	if (ba != 0)
		return (print_ch(nbr, base, ba));
	return (0);
}

static int	check_base(int ba, char *base)
{
	int	x;
	int	y;

	ba = 0;
	while (base[ba] != '\0')
		ba++;
	if (ba == 0 || ba == 1)
		return (0);
	x = 0;
	while (x < ba)
	{
		if (base[x] < 33 || base[x] > 126)
			return (0);
		if (base[x] == '-' || base[x] == '+')
			return (0);
		y = x;
		while (++y < ba)
		{
			if (base[x] == base[y])
				return (0);
		}
		x++;
	}
	return (ba);
}

static char	*print_ch(unsigned long nbr, char *base, int n)
{
	char	b[32];
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = 0;
	while (nbr > 0)
	{
		b[i++] = base[nbr % n];
		nbr = nbr / n;
	}
	if (i == 0)
		len = 1;
	else
		len = i;
	temp = malloc (sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	if (i == 0)
		temp[i] = base[0];
	while (--i >= 0)
		temp[len - i - 1] = b[i];
	temp[len] = 0;
	return (temp);
}
