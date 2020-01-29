#include "ft_printf.h"

int 	ft_addchar(t_printf *p)
{
	int 		c;
	int			i;

	i = 0;
	if (p->width > 0)
	{
		if (p->minus == 1)
			ft_add_buff_char(p, va_arg(p->li, int));
		if (p->zero == 1)
			c = '0';
		else
			c = ' ';
		while(++i < p->width)
			ft_add_buff_char(p, c);
		if (p->minus == 0)
			ft_add_buff_char(p, va_arg(p->li, int));
	}
	else
		ft_add_buff_char(p, va_arg(p->li, int));
	return (1);
}

int		ft_addstr(t_printf *p)
{
	char	*s;
	int		i;
	char	c;

	i = -1;
	s = strdup(va_arg(p->li, char*));
	if (s == NULL)
		s = strdup("(null)");///////////////////////////////////////////
	if (p->accuracy > 0 && p->accuracy < strlen(s))
		s[p->accuracy] = '\0';//////////////////////возможен инвалид врайт
	if (p->width > 0 && p->width > strlen(s))
	{
		if (p->zero == 1)
			c = '0';
		else
			c = ' ';
		if (p->minus == 1)
		{
			while(s[++i])
				ft_add_buff_char(p, s[i]);
			while(++i <= p->width)
				ft_add_buff_char(p, c);
		}
		else if (p->minus == 0)
		{
			while(++i < (p->width - strlen(s)))
				ft_add_buff_char(p, c);
			i = -1;
			while(s[++i])
				ft_add_buff_char(p, s[i]);
		}
	}
	else
	{
		while(s[++i])
			ft_add_buff_char(p, s[i]);
	}
	free(s);
	return (1);
}

int 	ft_addnbr(t_printf *p)
{
	int 	nbr;
	int		i;
	int 	t;
	int		k;
	char	c;

	nbr = va_arg(p->li, int);
	t = nbr;
	i = 1;
	k = 1;
	while (t > 9)
	{
		t /= 10;
		i *= 10;
		k++;
	}
	t = -1;
	if (p->width > 0 && k < p->width)
	{
		if (p->zero == 1)
			c = '0';
		else
			c = ' ';
		if (p->minus == 1)
		{
			while (i > 0)
			{
				ft_add_buff_char(p, (nbr / i) % 10 + 48);
				i /= 10;
			}
			while(++t < (p->width - k))
				ft_add_buff_char(p, c);
		}
		else if (p->minus == 0)
		{
			while(++t < (p->width - k))
				ft_add_buff_char(p, c);
			while (i > 0)
			{
				ft_add_buff_char(p, (nbr / i) % 10 + 48);
				i /= 10;
			}
		}
	}
	else
	{
		while (i > 0)
		{
			ft_add_buff_char(p, (nbr / i) % 10 + 48);
			i /= 10;
		}
	}
//	printf("nbr original: %d\n", nbr);
}

int 	ft_add_buff(t_printf *p)
{
	if (p->buff_index == buff_size)
		ft_realloc_buff(p);
	p->buff[p->buff_index++] = *p->str;
	return (1);
}

int 	ft_add_buff_char(t_printf *p, char c)
{
	if (p->buff_index == buff_size)
		ft_realloc_buff(p);
	p->buff[p->buff_index++] = c;
	return (1);
}

int		ft_add_buff_str(t_printf *p, char *s)
{
	int	i;

	i = -1;
	while(s[++i])
		ft_add_buff_char(p, s[i]);
	return (i);
}

//////////////////////////////////////////////
char	*ft_itoa_base(int value, int base)
{
	char	*s;
	long	n;
	int		sign;
	int		i;

	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

//////////////////////////////////////////////
//////////////////////////////////////////////
/////////////////////////////////////////////////
int		ft_add_p(t_printf *p)
{
	int		i;
	char	*s;

	i = va_arg(p->li, int);
	s = ft_itoa_base(i, 16);
	if (p->sharp == 1)
		ft_add_buff_str(p, "0x");
	ft_add_buff_str(p, s);
	free(s);
	return (1);
}

int		ft_add_ouxX(t_printf *p)
{
	int		i;
	char	*s;

	i = va_arg(p->li, int);
	//printf("i= %d\n", i);
	if (*p->str == 'o')
		s = ft_itoa_base(i, 8);
	else if (*p->str == 'u')
		s = ft_itoa_base(i, 10);
	else if (*p->str == 'x' || *p->str == 'X')//делать х маленькое
		s = ft_itoa_base(i, 16);
	ft_add_buff_str(p, s);
	free(s);
	return (1);
}