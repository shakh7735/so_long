/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:06:49 by eshakhge          #+#    #+#             */
/*   Updated: 2022/03/23 20:06:50 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_n(const char *s, int c)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return (1);
	if (c == 0)
		return (1);
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*copy;
	size_t	i;

	copy = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!copy)
		return (0);
	i = -1;
	if (!s)
		return (NULL);
	while (s[++i])
		copy[i] = s[i];
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin_up(char *s1, char const *s2)
{
	char	*d;
	size_t	i1;
	size_t	i2;
	int		j;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	d = malloc(sizeof(char) * (i1 + i2 + 1));
	if (!d)
		return (NULL);
	j = 0;
	if (s1)
	{
		while (*s1)
			d[j++] = *s1++;
	}
	while (*s2)
		d[j++] = *s2++;
	d[i1 + i2] = 0;
	if (s1)
		if (*s1)
			free (s1);
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	m;
	size_t			len_s;

	len_s = ft_strlen(s);
	if (len_s < start || len == 0)
		m = 0;
	else if (len_s - start + 1 > len)
		m = len;
	else
		m = len_s - start;
	d = (char *) malloc(m + 1);
	if (!d)
		return (NULL);
	len_s = 0;
	while (s[start] && len_s < m)
		d[len_s++] = s[start++];
	d[len_s] = '\0';
	return (d);
}
