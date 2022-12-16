/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:05:41 by eshakhge          #+#    #+#             */
/*   Updated: 2022/03/23 20:05:46 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = get_next_line_one(fd, buff[fd]);
	line = ft_line_up_to_temp(buff[fd]);
	buff[fd] = ft_strtrim_line(buff[fd], line);
	return (line);
}

char	*get_next_line_one(int fd, char *temp)
{
	char	*str;
	int		byte_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	byte_read = 1;
	while (!ft_strchr_n(temp, '\n') && byte_read != 0)
	{
		byte_read = read (fd, str, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(str);
			return (NULL);
		}
		str[byte_read] = 0;
		temp = ft_strjoin_up_free(temp, str);
	}
	free(str);
	return (temp);
}

char	*ft_line_up_to_temp(char *temp)
{
	char	*ptr;
	int		i;
	int		j;

	if (!temp)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (i == 0 && temp[i] != '\n')
		return (NULL);
	if (temp[i] == 0)
		i--;
	ptr = malloc(sizeof(char) * (i + 2));
	if (!ptr)
		return (NULL);
	j = -1;
	while (++j < i + 1)
		ptr[j] = temp[j];
	ptr[j] = 0;
	return (ptr);
}

char	*ft_strtrim_line(char *temp, char const *line)
{
	size_t	lent;
	size_t	lenl;
	size_t	i;
	char	*ptrt;

	if (!temp)
		return (NULL);
	if (!line)
	{
		free (temp);
		return (NULL);
	}
	lent = ft_strlen(temp);
	lenl = ft_strlen(line);
	ptrt = malloc (sizeof(char) * (lent - lenl + 1));
	if (!ptrt)
		return (NULL);
	i = lenl - 1;
	while (++i < lent)
		ptrt[i - lenl] = temp[i];
	ptrt[i - lenl] = 0;
	free(temp);
	return (ptrt);
}

char	*ft_strjoin_up_free(char *temp, char *str)
{
	char	*line;

	if (!str)
		return (NULL);
	line = ft_strjoin_up(temp, str);
	free(temp);
	return (line);
}
