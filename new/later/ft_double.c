/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:53:45 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/02/03 17:20:34 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_double.h"

void	ft_print(t_ullint len, int i)
{
	if (len < 2)
	{
		while (i < 63)
		{
			ft_putchar('0');
			i++;
		}
		ft_putchar('0' + len);
		return ;
	}
	i++;
	ft_print(len / 2, i);
	ft_putchar('0' + len % 2);
	return ;
}

t_double	ft_defldbl(long double *n)
{
	t_double		val;
	t_ullint		*nbr;

	nbr = (t_ullint*)malloc(sizeof(char) * 10);
	nbr = (t_ullint*)n;
	val.mantisa = nbr[0];
	val.sign = nbr[1] >> 15;
	val.order = (int)((nbr[1] & 0x7fff) - 16383);
	return (val);
}

t_bigdbl	ft_to_the_point(t_double val)
{
	t_bigdbl		to_the_point;
	t_bigdbl		two;
	t_bigdbl		buf;
	t_bigdbl		sum;
	int				i;

	to_the_point = ft_new_la(0);
	two = ft_new_la(2);
	i = val.order;
	while (i >= 0)
	{
		if (!((val.mantisa << (val.order - i)) >> 63))
		{
			i--;
			continue ;
		}
		buf = ft_pow_la(two, i--, 2);
		sum = ft_sum_la(to_the_point, buf);
		free(buf.coef);
		free(to_the_point.coef);
		to_the_point = sum;
	}
	return (to_the_point);
}

char			*ft_add_d(t_ldouble a, int i, int *len)
{
	t_bigdbl		to_the_point;
	t_double		val;
	char			*str;
	int				j;

	val = ft_defldbl(&a);
	to_the_point = ft_to_the_point(val);
	*len = ft_intlen((t_ullint)to_the_point.coef[to_the_point.size - 1]);
	str = (char*)malloc(sizeof(char) * ((to_the_point.size - 1) * 4 \
															+ *len + 1));
	ft_memset(str, '0', (to_the_point.size - 1) * 4 + *len);
	str[(to_the_point.size - 1) * 4 + *len] = 0;
	while (i < to_the_point.size)
	{
		j = 0;
		while (to_the_point.coef[i] > 0)
		{
			str[4 * i + j] = to_the_point.coef[i] % 10 + '0';
			to_the_point.coef[i] /= 10;
			j++;
		}
		i++;
	}
	return (ft_revstr(str));
}

char	*ft_revstr(char *str)
{
	size_t	i;
	size_t	len;
	char	buf;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		buf = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = buf;
		i++;
	}
	return (str);
}

int		ft_intlen(long long nbr)
{
	int			i;
	long long	p;

	i = 0;
	p = 10;
	while (i++ < 19)
	{
		if (nbr < p)
			return (i);
		p *= 10;
	}
	return (19);
}

int main()
{
	t_ldouble a = 2004321.123555;
	printf("%s", ft_add_d(a, 0));
	// t_double		val;
	// t_ldouble a = -0.15625;
	// val = ft_defdbl(&a);
	// printf("%lld", val.mantisa & 0x8000000000000000);
	// ft_print(val.mantisa >> 63, 0);
	// t_bigdbl		two;
	// two.size = 1;
	// two.coef = (short*)malloc(sizeof(short));
	// two.coef[0] = 5;
	// ft_printnbr(ft_pow_la(two, 6, 5));
}
