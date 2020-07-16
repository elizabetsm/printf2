#include "../includes/ft_printf.h"

int    length(char *format, t_struct *st, va_list ap) //21
{
    if (format[st->i] == 'h' && format[st->i + 1] == 'h')
    {
        st->i = st->i + 2;
        if (format[st->i] == 'd' || format[st->i] == 'i')
        {
            st->a = (char)va_arg(ap, int);
            specif_di(st, st->a, format);
        }
        else if (format[st->i] == 'o' || format[st->i] == 'u' || format[st->i] == 'x' || format[st->i] == 'X')
        {
            st->a = (unsigned char)va_arg(ap, int);
            specif_uoxX(st, format, st->a);
        }
    }
    else if (format[st->i] == 'h')
		return(short_length(format, st, ap));
    else if (format[st->i] == 'l' || 
	(format[st->i] == 'l' && format[st->i + 1] == 'l'))
		return (long_length(format, st, ap));
    else
		return (0);
	return (1);
}

int short_length(char *format, t_struct *st, va_list ap)
{
	st->i++;
    if (format[st->i] == 'd' || format[st->i] == 'i')
    {
        st->a = (short int)va_arg(ap, int);
        specif_di(st, st->a, format);
    }
    else if (format[st->i] == 'o' || format[st->i] == 'u' || format[st->i] == 'x' || format[st->i] == 'X')
    {
        st->a = (unsigned short int)va_arg(ap, int);
        specif_uoxX(st, format, st->a);
    }
	return (1);
}

int long_length(char *format, t_struct *st, va_list ap)
{
	  st->i++;
        if (format[st->i] == 'l')
            st->i++;
        if (format[st->i] == 'd' || format[st->i] == 'i')
        {
            st->d = va_arg(ap, long long int);
            st->tmp = itoa(st->d);
			st->i++;
        }
        else if (format[st->i] == 'o' || format[st->i] == 'u' || format[st->i] == 'x' || format[st->i] == 'X')
        {
            st->o = va_arg(ap, unsigned long long int);
            specif_uoxX(st, format, st->o);
        }
	return (1);
}