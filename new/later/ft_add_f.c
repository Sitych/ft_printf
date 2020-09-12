/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 18:37:01 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/01/30 18:54:10 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_llitoa(long long nbr)
{
	char		*str;
	size_t		i;
	int			sign;
	t_ullint	val;

	sign = (nbr < 0) ? -1 : 0;
	i = ft_intlen(nbr);
	i = (nbr > 0) ? i + 1 : i + 2;
	str = (char*)malloc(sizeof(char) * (i + 1));
	str[i] = 0;
	val = (nbr < 0) ? -(t_ullint)nbr : (t_ullint)nbr;
	while (i-- + sign)
	{
		str[i] = '0' + val % 10;
		val = val / 10;
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);
}

void	ft_add_d_buff(long long to_the_point, long long after_point)
{
	char	*str;
	
	str = ft_llitoa(to_the_point);
	// ft_add_buff_str(p, str);
	// ft_add_buff_char(p, '.');
	printf("%s", str);
	printf("%c", '.');
	ft_strdel(&str);
	str = ft_llitoa(after_point);
	// ft_add_buff_str(p, str);
	printf("%s", str);
	ft_strdel(&str);
}

// int		ft_add_d()
int		ft_add_d(t_printf *p)
{
	long long	to_the_point;
	long long	after_point;
	long double	nbr;
	char		*str;
	char		*buf;
	int			len;
	char		c;

	int	width = 6;
	int accuracy = 6;
	int	zero = 0;
	int minus = 1;
	int	plus = 1;
	
	// nbr = va_arg(p->li, long double);
	nbr = 20.5;
	len = ft_intlen(nbr);
	to_the_point = (long long)nbr;
	after_point = (long long)((nbr - (long double)to_the_point) * ft_pow(10, accuracy));
	if (width > 0 && len < width)
	{
		c = (zero == 1) ? '0' : ' ';
		if (minus == 1)
		{
			(plus == 1 && to_the_point > 0) ? ft_add_buff_char(p, '+') : 0;
			ft_add_d_buff(to_the_point, after_point);
			while (len-- - width)
				ft_add_buff_char(p, c);
		}
		else
		{
			while (len-- - width)
				ft_add_buff_char(p, c);
			(plus == 1 && to_the_point > 0) ? ft_add_buff_char(p, '+') : 0;
			ft_add_d_buff(to_the_point, after_point);
		}
	}

	return (0);
}
