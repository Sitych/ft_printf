/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 18:37:01 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/01/29 23:36:05 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// void	ft_print(t_ullint len, int i)
// {
// 	if (len < 2)
// 	{
// 		while (i < 64)
// 		{
// 			ft_putchar('0');
// 			i++;
// 		}
// 		ft_putchar('0' + len);
// 		return ;
// 	}
// 	i++;
// 	ft_print(len / 2, i);
// 	ft_putchar('0' + len % 2);
// 	return ;
// }

t_ldouble	ft_pow(int a, int x)
{
	t_ldouble rslt;

	rslt = 1.0;
	if (x > 0)
	{
		while (x--)
			rslt = rslt * a;
	}
	else if (x < 0)
	{
		while (x++)
			rslt = rslt / a;
	}
	else
		rslt = (t_ldouble)a;
	return (rslt);
}

// // int		ft_add_d(t_printf *p)
// int		ft_add_d()
// {
// 	t_ldouble		*orig;
// 	t_ldouble kek;
// 	int				accuracy;
// 	int				width;
// 	char			str[81];
// 	unsigned short int		order;
// 	t_ullint		*nbr;
// 	t_ullint		mantisa;

// 	// *orig = va_arg(p->li, double);
// 	t_ldouble a;
// 	a = 20.9;
// 	orig = &a;
// 	nbr = (t_ullint*)malloc(sizeof(char) * 10);
// 	nbr = (t_ullint*)orig;
// 	mantisa = *nbr;
// 	order = (unsigned short int)nbr[1];
// 	// *nbr = *nbr & 0x7fffffffffffffff;
// 	// printf("%lld\n", *mantissa);
// 	for (int i = 0; i < 2; i++)
// 		printf("%llx\n",nbr[i]);
// 	printf("mantisa = %lld\n", mantisa);
// 	ft_print(mantisa, 0);
// 	printf("\n");
// 	printf("order = %d\n", order - 16383);
// 	printf("orig = %.51Lf\n", *orig);
// 	printf("a = %.51Lf\n", a);
// 	kek = 0.0;
// 	int i = 0;
// 	order = order - 16383;
// 	printf("%d\n", order);
// 	while (mantisa)
// 	{
// 		kek = kek + ft_pow(2, order) * (mantisa & 0x8000000000000000);
// 		printf("orig = %Lf mantisa = %lld\n", kek, mantisa & 0x800000000000 );
// 		// ft_putstr("mantisa = ");
// 		// ft_print(mantisa, 0);
// 		// ft_putchar('\n');
// 		// printf("bit = %lld \n", mantisa & 0x8000000000000000);
// 		mantisa = mantisa << 1;
// 		order--;
// 		i++;
// 	}
// 	printf("\n%d", i);
//     return (0);
// }

char	*ft_llitoa(long long nbr, int *len)
{
	char		*str;
	size_t		i;
	int			sign;
	t_ullint	val;

	i = (nbr > 0) ? 1 : 2;
	val = (nbr < 0) ? -(t_ullint)nbr : (t_ullint)nbr;
	sign = (nbr < 0) ? -1 : 0;
	while ((val = val / 10) > 1)
		i++;
	*len = (int)i;
	str = (char*)malloc(sizeof(char) * (i + 2));
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

// int		ft_add_d(t_printf *p)
int		ft_add_d()
{
	long long	to_the_point;
	long long	after_point;
	long double	nbr;
	char		*str;
	char		*buf;
	int			len;
	int			len2;

	// nbr = va_arg(p->li, long double);
	nbr = 20.9;
	to_the_point = (long long)nbr;
	after_point = (long long)((nbr - (long double)to_the_point) * ft_pow(10, 6));
	str = ft_llitoa(to_the_point, &len);
	str[len] = '.';
	buf = str + len + 1;
	buf = ft_llitoa(after_point, &len2);
	printf("%s", str);
	return (0);
}

int main()
{
	ft_add_d();
}
