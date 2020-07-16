#include "../includes/ft_printf.h"

void    specif_di(t_struct *st, long long int a, char *format) 
{
	if (st->wdht == 0 && st->f_space == 1)
	{
		if (((st->f_pres + st->f_minus + st->f_resh + st->f_nul + st->f_plus) == 0) && st->specif == 'd' && st->a > 0)
			st->schet = st->schet + re_putchar(' ');
	}
	if ((st->f_nul == 1 || st->f_space == 1) && st->a < 0 && st->f_plus == 0)
	{
		st->schet = st->schet + re_putchar('-');
		st->a *= -1;
		st->num_flags = 1;
	}
    st->tmp = itoa(st->a);
    st->i++;
}

void    specif_uoxX(t_struct *st, char *format, unsigned long long int a)
{
	int trig;

	trig = 0;
    if (format[st->i] == 'o')
	{
    	st->specif = 'o';
		octal(a, st);
		st->i++;
	}
    else if (format[st->i] == 'x' || format[st->i] == 'X')
    {
    	st->specif = 'x';
		if (format[st->i] == 'X')
			trig = 1;
		hexadecimal(a, trig, st);
		st->i++;
	}
	else if (format[st->i] == 'u')
	{
		st->tmp = itoa(a);
		st->i++;
	}
}

int hexadecimal2(long long int a, int trig, t_struct *st)//22
{
	int i;
	int f;

	f = 0;
		while (a > 0)
	{
		i = a % 16;
		if (i > 9)
		{
			if (trig == 1)
				st->l[0] = (i - 10) + 'A';
		 	else
		 		st->l[0] = (i - 10) + 'a';
		 	st->l[1] = '\0';
		}
		else 
			st->l = itoa(i);
		st->tmp = ft_strjoin(st->str, st->l);
		free(st->str);
		st->str = st->tmp;
		a = a/16;
		f++;
	}
	return (f);
}

void		hexadecimal(long long int a, int trig, t_struct *st) //16
{
	int	f;
	
	f = 0;
	if (a == 0)
	{
		st->tmp[0] = '0';
		st->nul= 1;
		return ;
	}
	st->l = ft_memalloc(2);
	st->str = ft_memalloc(100);
	f = hexadecimal2(a, trig, st);
	st->tmp = ft_memalloc(40);
	a = 0;
	while(--f >= 0)
		st->tmp[a++] = st->str[f];
	st->tmp[a] = '\0';
}

void	octal(unsigned long long int a, t_struct *st)
{
	int	i;
	int	f;
	
	f = 0;
	if (a == 0)
	{
		st->nul = 1;
		st->tmp[0] = '0';
		return ;
	}
	st->str = ft_memalloc(100);
	while (a > 0)
	{
		i = a % 8;
		st->tmp = ft_strjoin(st->str, itoa(i));
		free(st->str);
		st->str = st->tmp;
		a = a/8;
		f++;
	}
	st->tmp = ft_memalloc(40);
	a = 0;
	while(--f >= 0)
		st->tmp[a++] = st->str[f];
	st->tmp[a] = '\0';
}