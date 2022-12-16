/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:06:13 by eshakhge          #+#    #+#             */
/*   Updated: 2022/03/23 20:07:59 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include "../game.h"
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# ifndef OPEN_MAX

#  define OPEN_MAX 65535

# endif

char	*get_next_line(int fd);
char	*ft_strjoin_up(char *s1, char const *s2);
int		ft_strchr_n(const char *s, int c);
char	*ft_strtrim_line(char *temp, char const *line);
char	*ft_line_up_to_temp(char *temp);
void	ft_freemalloc(char *s);
char	*ft_strjoin_up_free(char *temp, char *str);
void	ft_bzero(void *str, size_t n);
char	*get_next_line_one(int fd, char *temp);

#endif
