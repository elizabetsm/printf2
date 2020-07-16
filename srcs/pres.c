#include "../includes/ft_printf.h"

void	pres_print(t_struct *st)
{
	// if (st->f_wdht == 1 && st->wdth_pres == 0)
	// 		st->tmp == " ";
	if (st->wdth_pres == 0)
	{
		if (st->specif == 'o' && st->f_resh == 1)
			st->tmp == "0";
		else
			st->tmp = "";
		return ;
	}
	if (st->c_trig != 1)
	{
		if (st->a < 0)
		{
			st->schet += re_putchar('-');
			free(st->tmp);
			st->tmp = itoa((st->a * -1));
		}
		if(st->specif == 's')
			pres_str(st);
		else
			pres_num(st);
	}
}

void	pres_str(t_struct *st)
{
	int i;
	long int len;

	len = ft_strlen(st->tmp);
	i = 0;
	if (len == 0 && st->wdht == 0)
		return ;
	if ((st->wdth_pres < len) && st->wdth_pres >= 0)
	{
		while (i < st->wdth_pres)
		{
			st->schet = st->schet + re_putchar(st->tmp[i]);
			i++;
		}
	}
	else
	{
		// printf("len = %d\n", ft_strlen(st->tmp));
		while (st->tmp[i])
		{
			st->schet = st->schet + re_putchar(st->tmp[i]);
			i++;
		}
	}
}

void	pres_num(t_struct *st)
{
	int d = st->wdth_pres - ft_strlen(st->tmp);
	if ((st->wdth_pres > ft_strlen(st->tmp)))
		{
			while (d > 0)
			{
				st->schet = st->schet + re_putchar('0');
				d--;
			}
		}
		else if ((st->wdth_pres < ft_strlen(st->tmp)))
			return ;
}