t_bigdbl	ft_after_point(t_double val)
{
	t_bigdbl		after_point;
	t_bigdbl		five;
	t_bigdbl		ten;
	t_bigdbl		buf;
	t_bigdbl		sum;
	int				i;
	t_ullint		mant;

	after_point.size = 1;
	after_point.coef = (short*)malloc(sizeof(short));
	after_point.coef[0] = 0;
	five.size = 1;
	five.coef = (short*)malloc(sizeof(short));
	five.coef[0] = 5;
	ten.size = 1;
	ten.coef = (short*)malloc(sizeof(short));
	ten.coef[0] = 10;
	i = 0;
	printf("%d\n", val.order);
	mant = (val.mantisa << val.order) >> val.order;
	ft_print(val.mantisa, 0);
	printf("\n");
	ft_print(mant, 0);
	printf("\n");	
	while (mant)
	{
		printf("bit = %d\n", (mant << i) >> 63);
		printf("i = %d\n", i);
		// ft_print(mant, 0);
		// printf("\n");
		if (!((mant = mant << i) >> 63))
		{
			i++;
			continue ;
		}
		buf = ft_pow_la(five, ++i, 5);
		after_point = ft_mul_la(after_point, );
		sum = ft_sum_la(after_point, buf);
		after_point = sum;
		if (!mant)
			break ;
	}
	return (after_point);
}

t_bigdbl	ft_mul(t_bigdbl a, t_bigdbl b)
{
	t_bigdbl		rslt;
	unsigned long	i;
	unsigned long	j;
	unsigned long	temp;
	unsigned long	carry;

	i = -1;
	while (i++ <= (a.size + b.size))
		rslt.coef[i] = 0;
	i = -1;
	while (i++ <= a.size)
	{
		carry = 0;
		j = -1;
		while (j++ < b.size)
		{
			temp = a.coef[i] * b.coef[j] + rslt.coef[i + j] + carry;
			carry = temp / BASE;
			rslt.coef[i + j] = temp - carry * BASE;
		}
		rslt.coef[i + j] = temp - carry * BASE;
	}
	i = a.size + b.size - 1;
	rslt.size = (rslt.coef[i] == 0) ? i : i + 1;
	return (rslt);
}
