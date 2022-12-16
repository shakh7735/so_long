/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:58:27 by eshakhge          #+#    #+#             */
/*   Updated: 2022/04/03 15:20:51 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_flag
{
	int	minus;
	int	plus;
	int	zero;
	int	point;
	int	spc;
	int	resh;
	int	index;
	int	wdt;
	int	ttl;
	int	ident;
	int	pref_minus;
	int	len;
}	t_flags;

int		ft_printf(const char *str, ...);
int		ft_flags_search(t_flags *f, const char *str, int index);
int		ft_print_args(va_list args, t_flags *f);
int		ft_putchar(int c);
int		ft_putstr(const char *s);
int		ft_print_char(char c, t_flags *f);
int		ft_loop_putchar(char c, int size);
int		ft_print_str(char *str, t_flags *f);
int		ft_print_ptr(unsigned long nbr, t_flags *f);
int		ft_print_num(long int nbr, t_flags *f);
int		ft_print_u(unsigned int nbr, t_flags *f);
int		ft_print_xx(unsigned int nbr, t_flags *f);
t_flags	*ft_flags_init(t_flags *f);
size_t	ft_strlen(char const *str);
char	*ft_putnbr_base(unsigned long nbr, char *base);
char	ft_chek_specif(char c, char *str);
void	ft_set_flags(t_flags *f, char c);

#endif
