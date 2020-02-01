/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:53:45 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/02/02 00:36:01 by qjosmyn          ###   ########.fr       */
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

t_bigdbl	ft_new_la(unsigned int nbr)
{
	t_bigdbl		rslt;
	size_t			i;
	unsigned int	n;

	n = nbr;
	i = 1;
	while (n > BASE)
	{
		n = n / BASE;
		i++;
	}
	rslt.size = i;
	rslt.coef = (short*)malloc(sizeof(short) * i);
	i = 0;
	while (i < rslt.size)
	{
		rslt.coef[i] = nbr % BASE;
		nbr = nbr / BASE;
		i++;
	}
	return (rslt);
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
	while (i > 0)
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

// t_bigdbl	ft_after_point(t_double val)
// {
// 	t_bigdbl		after_point;
// 	t_bigdbl		five;
// 	t_bigdbl		ten;
// 	t_bigdbl		buf;
// 	t_bigdbl		sum;
// 	int				i;
// 	t_ullint		mant;

// 	after_point.size = 1;
// 	after_point.coef = (short*)malloc(sizeof(short));
// 	after_point.coef[0] = 0;
// 	five.size = 1;
// 	five.coef = (short*)malloc(sizeof(short));
// 	five.coef[0] = 5;
// 	ten.size = 1;
// 	ten.coef = (short*)malloc(sizeof(short));
// 	ten.coef[0] = 10;
// 	i = 0;
// 	printf("%d\n", val.order);
// 	mant = (val.mantisa << val.order) >> val.order;
// 	ft_print(val.mantisa, 0);
// 	printf("\n");
// 	ft_print(mant, 0);
// 	printf("\n");	
// 	while (mant)
// 	{
// 		printf("bit = %d\n", (mant << i) >> 63);
// 		printf("i = %d\n", i);
// 		// ft_print(mant, 0);
// 		// printf("\n");
// 		if (!((mant = mant << i) >> 63))
// 		{
// 			i++;
// 			continue ;
// 		}
// 		buf = ft_pow_la(five, ++i, 5);
// 		after_point = ft_mul_la(after_point, );
// 		sum = ft_sum_la(after_point, buf);
// 		after_point = sum;
// 		if (!mant)
// 			break ;
// 	}
// 	return (after_point);
// }

int		ft_add_d()
{
	t_bigdbl		to_the_point;
	t_bigdbl		after_point;
	t_double 		val;

	t_ldouble a = 20001111111111111.123555;
	double b = 20001111111111111.123551;
	// t_ldouble c = (t_ldouble)b;
	printf("orig %f\n", b);
	a = (t_ullint)b;
	val = ft_defldbl(&a);
	to_the_point = ft_to_the_point(val);
	ft_printnbr(to_the_point);

	// ft_printnbr(ft_new_la(54321));
	// after_point = ft_after_point(val);
	// ft_printnbr(after_point);
	// ft_printnbr(to_the_point);
	// printf("mantisa = %lld\n", val.mantisa);
	// ft_print(val.mantisa, 0);
	// printf("\n");
	// printf("order = %d\n", val.order);
	// printf("a = %.51Lf\n", a);
    return (0);
}

int		ft_intlen(long long nbr)
{
	int 		i;
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
    ft_add_d();
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
