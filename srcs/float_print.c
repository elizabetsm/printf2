#include "../includes/ft_printf.h"

void    ft_out(char *fp, char *sp, t_struct *st)
{
    int i;
    int j;
    int k;

    rounding(sp, st);

    st->tmp = ft_memalloc(ft_strlen(st->fp) + st->round + 2);

    i = 0;
    j = 0;
//    if (st->sign_bit == 1)
//	{
//		st->tmp[i] = '-';
//		i++;
//	}
//    else if (st->f_plus == 1)
//	{
//		st->tmp[i] = '+';
//		i++;
//	}
    if (st->f_zero == 0)
    {
        while (st->fp[j] == '0')
            j++;
        while (st->fp[j] != '\0')
        {
            st->tmp[i] = st->fp[j];
            i++;
            j++;
        }
    }
    else
	{
		st->tmp[i] = '0';
		i++;
	}
    if (st->round != 0 || st->f_resh != 0)
	{
		st->tmp[i] = '.';
		i++;
	}
    j = 0;
    k = ft_strlen(st->sp);
    while (j < st->round && j < k)
    {
		st->tmp[i] = st->sp[j];
        j++;
        i++;
    }
    while (j < st->round)
    {
		st->tmp[i] = '0';
        j++;
        i++;
    }
//    ft_otvet(st);
}

void 	zero_round(t_struct *st)
{
	int i;

	i = 0;
	while (st->fp[i] != '\0')
		i++;
	i--;
	if ((st->fp[i] == '1' || st->fp[i] == '3' ||
	st->fp[i] == '5' || st->fp[i] == '7' ||
	st->fp[i] == '9') && st->sp[st->round] >= '5')
		rounding_fp(st);
}

void    rounding(char *sp, t_struct *st) //округление
{
    int i;
    int j;
    char *arr;

    j = 0;
    i = ft_strlen(sp);
	if (st->round == 0)
		zero_round(st);
    if (st->round < i && sp[st->round] >= '5')
    {
        arr = ft_memalloc(st->round + 1);
        arr[j] = '1';
        while (j < st->round - 1)
        {
            j++;
            arr[j] = '0';
        }
        sum_reverse(sp, arr, st);
    }
}

//void print_float(char *fp, char *sp, t_struct *st, t_sun eeei)
//{
//    if (st->f_minus == 1)
//    {
//        if (st->f_plus == 1)
//        {
//            if (eeei.v.sign == 1)
//                st->schet = st->schet + re_putchar('-');
//            else
//                st->schet = st->schet + re_putchar('+');
//        }
//
//
//    }
////    else if (st->f_minus == 0)
////        print_else(format, st);
//    ft_out(st->fp, st->sp, st);
//}