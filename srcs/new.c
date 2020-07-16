#include "../includes/ft_printf.h"

void	flags(char *format, t_struct *st, va_list ap)
{
	while (format[st->i] >= 32 && format[st->i] <= 48 && format[st->i] != 37) 
	{
		if (format[st->i] == '+')
			st->f_plus = 1;
		if (format[st->i] == '.')
			st->f_pres = 1;
		else if (format[st->i] == '-')
			st->f_minus = 1;
		else if (format[st->i] == ' ')
			st->f_space = 1;
		else if (format[st->i] == '#')
			st->f_resh = 1;
		else if (format[st->i] == '0')
			st->f_nul = 1;
		st->i++;
	}
	if (st->f_minus == 1) 
		st->f_nul = 0;
}

void	pres_check(char *format, t_struct *st, va_list ap)
{
	if (format[st->i] == '.')
	{
		pres_width(format, st, ap);	
		st->f_pres = 1;
//		if (st->wdth_pres != 0 && )
//			st->f_nul = 0;
	}
}

void		pres_width(char *format, t_struct *st, va_list ap)
{
	int		j;
	char	*wdht;

	j = 0;
	wdht = ft_memalloc(20);
	if (format[st->i - 1] == '*' || (format[st->i - 2]== '*' && format[st->i - 1] != '%'))
	    st->wdth_pres = va_arg(ap, int);
    else
    {
        while (format[st->i] != '\0' && format[st->i] != '%') 
		{
            if (format[st->i] >= 48 && format[st->i] <= 57)
			{
                wdht[j] = format[st->i];
                j++;
            }
            st->i++;
            if (format[st->i] == '.' || (format[st->i] > 96 && format[st->i] < 123)
                || format[st->i] == st->specif)
                break;
        }
        st->wdth_pres = ft_atoi(wdht);
        if (format[st->i - 1] >= 65 && format[st->i - 1] <= 122)
            st->i--;
    }
        free(wdht);
}

void		width(char *format, t_struct *st, va_list ap)
{
	if(format[st->i - 1] == '.' || (format[st->i - 2]== '.' && format[st->i - 1] != '%'))
	{
		pres_width(format, st, ap);
		st->f_pres = 1;
	}
	else 
	{	detect_wdth(format, st, ap);
		pres_check(format, st, ap);
	}
}

void detect_wdth(char *format, t_struct *st, va_list ap)
{
	int		i;
	int		j;
	char	*wdht;

	i = st->i;
	j = 0;
	if (format[st->i] == '*')
	    st->wdht = va_arg(ap, int);
    else
    {
		wdht = ft_memalloc(20);
		while (format[i] != '\0' && format[i] != '%')
			{
				if (format[i] >= 48 && format[i] <= 57)
				{
					wdht[j] = format[i];
					j++;
					st->f_wdht = 1;
				}
				i++;
				if (format[i] == '.' || (format[i] > 96 && format[i] < 123)
				|| format[i] == st->specif)
					break ;
			}
			st->wdht = ft_atoi(wdht);
			st->i = st->i + j;
			free(wdht);
	}
}

void	ft_free(t_struct *st)
{
	// free(st->tmp);
	st->f_plus = 0; // триггер
	st->f_minus = 0;
	st->f_space = 0;
	st->f_resh = 0;
	st->f_nul = 0;
	st->wdht = 0;
	st->wdth_pres = 0;
	st->f_pres = 0;
	// free(st->tmp);
}