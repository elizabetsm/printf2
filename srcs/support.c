#include "../includes/ft_printf.h"

int		ft_length(long long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while ((n / 10) > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*itoa(long long int n) //22
{
	char			*a;
	int				len;
	long long int	tmp;
	
	len = ft_length(n);
	tmp = n;
	if (!(a = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n == 0)
		a[0] = '0';
	if (n < 0)
	{
		a[0] = '-';
		n = n * (-1);
	}
	a[len] = '\0';
	while (n > 0)
	{
		len--;
		a[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (a);
}

void	init(t_struct *st)
{
	st->tmp = ft_memalloc(200);
	st->a = 0;
	st->f_plus = 0; // триггер
	st->f_minus = 0;
	st->f_space = 0;
	st->f_resh = 0;
	st->f_nul = 0;
	st->wdht = 0;
	st->specif = ' ';
	st->num_flags = 0;
	st->wdth_pres = 0;
	st->f_wdht = 0;
}