#include "../includes/ft_printf.h"
# define SIZE_E 1023
# define SIZE_M 52

//void    bit_parcer(long double f)
//{
//    t_sun eeei;
//    //unsigned displayMask = 1 << 22;
//    int c;
//
//    eeei.f = f;
//    printf("\n");
////    printf("%d_ %d_ %d  %f\n", eeei.v.sign, eeei.v.exp, eeei.v.mant, eeei.f);
//    for (c=0; c<=23; c++)
//    {
//        ft_putchar(eeei.v.mant & (1 << c) ? '1' : '0');
//        //eeei.v.mant <<= 1;
//
////        if (c % 8 == 0)
////            putchar(' ');
//    }
//}

void    *ft_cpy(char *newptr, char *ptr, int size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (ptr[i] != '\0')
    {
        newptr[i] = ptr[i];
        i++;
    }
    while (i < size)
    {
        newptr[i] = '0';
        i++;
    }
    newptr[i] = '\0';
    return (newptr);
}

void	*ft_realloc(void *ptr, size_t size)
{
    char	*newptr;

    if (!size && ptr)
    {
        if (!(newptr = (char *)malloc(1)))
            return (NULL);
        ft_memdel(&ptr);
        return (newptr);
    }
    if (!(newptr = (char *)malloc(size + 1)))
        return (NULL);
    if (ptr)
    {
        ft_cpy(newptr, ptr, size);
//        free(ptr);
        ft_memdel(&ptr);
    }
    return (newptr);
}

void    *get_char(char *arr)
{
    char *mas;
    int i;
    int j;
    char tmp;

    j = ft_strlen(arr);
    i = 0;
    mas = ft_memalloc(ft_strlen(arr) + 1);
    while (arr[i] != '\0')
    {
        mas[i] = arr[j - 1];
        i++;
        j--;
    }
    mas[i] = '\0';
    ft_memdel(&arr);
    arr = mas;
    return (arr);
}

void 	*sum_char2(char *ans, int i, int j)
{
	char *newptr;

	while (ans[i] != '\0')
	{
		if (ans[i] > '9')
		{
			if (ans[i + 1] == '\0')
			{
				newptr = ft_strnew(j + 1);
				ft_strcpy(newptr, ans);
				newptr[i] -= 10;
				newptr[i + 1] = 49;
				newptr[i + 2] = '\0';
				ft_memdel(&ans);
				return (newptr);
			}
			else
			{
				ans[i + 1]++;
				ans[i] -= 10;
			}
		}
		i++;
	}
	return (ans);
}

void    *sum_char(char *ans, char *tmp, t_struct *st)
{
    int i;
    int j;

    i = ft_strlen(ans);
    j = ft_strlen(tmp);
    while ((i - 1) == j || j > i)
    {
        ans = ft_realloc(ans, (i*2));
        i = ft_strlen(ans);
        j = ft_strlen(tmp);
    }

    i = 0;
    while (tmp[i] != '\0' && ans[i] != '\0')
    {
		ans[i] += tmp[i] - '0';
		i++;
	}
    i = 0;
    ans = sum_char2(ans, i, j);
    return (ans);
}

//void    *two_degree(char *arr, t_struct *st)
//{
//    char *tm;
//    char *newptr;
//    int i;
//
//    tm = ft_memalloc(ft_strlen(arr));
//    ft_strcpy(tm, arr);
//    i = 0;
//    while (arr[i] != '\0')
//    {
//    	arr[i] += tm[i] - '0';
//        i++;
//    }
//    i = 0;
//    while (arr[i] != '\0')
//    {
//        if (arr[i + 1] == '\0' && arr[i] > '9')
//        {
//            newptr = ft_memalloc(i + 3);
//            ft_strcpy(newptr, arr);
//            newptr[i] -= 10;
//            newptr[i + 1] = 49;
//            newptr[i + 2] = '\0';
////            arr = newptr;
////            ft_memdel(arr);
//            ft_memdel(&tm);
//            return (newptr);
//        }
//        if (arr[i] > '9')
//        {
//			arr[i] -= 10;
//			arr[i + 1]++;
//        }
//        i++;
//    }
//    ft_memdel(&tm);
//    return (arr);
//}

void 	two_degree2(t_struct *st)
{
	char *newptr;
	int i;

	i = 0;
	while (st->arr[i] != '\0')
	{
		if (st->arr[i + 1] == '\0' && st->arr[i] > '9')
		{
			newptr = ft_memalloc(i + 3);
			ft_strcpy(newptr, st->arr);
			newptr[i] -= 10;
			newptr[i + 1] = 49;
			newptr[i + 2] = '\0';
			ft_memdel(&st->arr);
			st->arr = newptr;
			return ;
		}
		if (st->arr[i] > '9')
		{
			st->arr[i] -= 10;
			st->arr[i + 1]++;
		}
		i++;
	}
}

void    two_degree(t_struct *st)
{
	char *tm;
	int i;

	i = ft_strlen(st->arr);
	tm = ft_memalloc(i + 1);
	ft_strcpy(tm, st->arr);
	i = 0;
	while (st->arr[i] != '\0')
	{
		st->arr[i] += tm[i] - '0';
		i++;
	}
	ft_memdel((void **)(&tm));
	two_degree2(st);
}

void    rounding_fp(t_struct *st)
{
    char *arr;

    arr = ft_memalloc(2);
    arr[0] = '1';
    arr[1] = '\0';
    st->fp = get_char(st->fp);
    sum_char(st->fp, arr, st);
    st->fp = get_char(st->fp);
    st->f_zero = 0;
    st->sp[0] -= 10;
}

int		sum_reverse2(const char *arr, t_struct *st)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (arr[j] != '\0')
	{
		st->sp[i] += arr[j] - '0';
		k = i;
		while (k > 0)
		{
			if (st->sp[k] > '9')
			{
				st->sp[k - 1]++;
				st->sp[k] -= 10;
			}
			k--;
		}
		i++;
		j++;
	}
	return (k);
}

void    sum_reverse(char *ans, char *tmp, t_struct *st)
{
    int i;
    int j;
    int k;
    char symb;
    char *arr;

    i = ft_strlen(st->sp);
    j = ft_strlen(tmp);
	arr = ft_memalloc(j + 1);
	ft_strcpy(arr, tmp);
    arr = get_char(arr);
    while ((i - 1) == j || j > i)
    {
        st->sp = ft_realloc(st->sp, (i*2));
        i = ft_strlen(st->sp);
    }
    k = sum_reverse2(arr, st);
    if (k == 0 && st->sp[k] > '9')
        rounding_fp(st);
}

void    *get_zero(char *arr)
{
    char *newptr;
    int i;

    newptr = ft_memalloc(ft_strlen(arr) + 3);
    i = 0;
    while (arr[i] != '\0')
    {
        newptr[i] = arr[i];
        i++;
    }
    newptr[i] = '0';
    newptr[i + 1] = '\0';
    ft_memdel((void **)(&arr));
    return (newptr);
}

void 	*multiplication2(const char *ar, char *newptr)
{
	int j;

	j = 0;
	while (ar[j] != '\0')
	{
		newptr[j] += ar[j] - '0';
		if (newptr[j] > '9')
		{
			if (newptr[j + 1] == '\0')
			{
				newptr[j + 1] = '0';
				newptr[j + 2] = '\0';
			}
			newptr[j + 1]++;
			newptr[j] -= 10;
		}
		j++;
	}
	return (newptr);
}

void    *multiplication(char *arr, int num, int deg)
{
    int i;
    char *newptr;

    newptr = ft_memalloc(ft_strlen(arr) + 3);
    ft_strcpy(newptr, arr);
    i = 0;
    while (i < num - 1)
    {
    	newptr = multiplication2(arr, newptr);
        i++;
    }
    free(arr);
    if (ft_strlen(newptr) < deg)
        newptr = get_zero(newptr);
    return (newptr);
}

int exp_shift(t_sun eeei)
{
    int a;

    a = eeei.v.exp - SIZE_E;
    return (a);
}

int		check_inf_nan(t_sun eeei, t_struct *st)
{
	if (eeei.v.exp == 2047 && eeei.v.mant == 0)
	{
		st->tmp = ft_memalloc(5);
//		if (st->sign_bit == 1)
//			st->tmp[0] = '-';
		st->tmp = ft_strjoin(st->tmp, "inf");
		return (1);
	}
	else if (eeei.v.exp == 2047)
	{
		st->tmp = ft_memalloc(4);
		st->tmp = ft_strjoin(st->tmp, "nan");
		return (1);
	}
	return (0);
}

int     check_zero(t_sun eeei, t_struct *st)
{
    int i;
    int j;

    i = -1;
    j = 0;
    if (eeei.v.exp == 0 && eeei.v.mant == 0)
    {
    	st->tmp = ft_memalloc(st->round + 4);
//        if (st->sign_bit == 1)
//			st->tmp[++i] = '-';
//		else if (st->f_plus == 1)
//			st->tmp[++i] = '+';
		st->tmp[++i] = '0';
        if (st->round != 0 || st->f_resh != 0)
			st->tmp[++i] = '.';
        while (j < st->round)
		{
			st->tmp[++i] = '0';
			j++;
		}
        return (1);
    }
    i = check_inf_nan(eeei, st);
    if (i == 1)
    	return (1);
	return (0);
}

void    after_point(t_sun eeei, t_struct *st)
{
    int count;
    int c;
    int b;

	st->arr = ft_memalloc(2);
	st->arr[0] = '1';
    count = 0;
    for (c = (SIZE_M - st->shift - 1); c >= 0; c--)
    {
        count++;
        eeei.v.mant & (1L << c) ? (b = 1) : (b = 0);
        if (c > SIZE_M)
        {
			st->arr = multiplication(st->arr, 5, count);
            continue;
        }
		st->arr = multiplication(st->arr, 5, count);
        if (c == SIZE_M)
            sum_reverse(st->sp, st->arr, st);
        if (b == 1)
            sum_reverse(st->sp, st->arr, st);
    }
    ft_memdel(&st->arr);
}

void    init_chars(t_struct *st)
{
	st->size = 8;
	st->arr = ft_memalloc(2);
	st->arr[0] = '1';
	st->arr[1] = '\0';
    st->sp = ft_memalloc(st->size);
    st->sp = ft_realloc(st->sp, st->size);
    st->fp = ft_memalloc(st->size);
    st->fp = ft_realloc(st->fp, st->size);
    st->f_zero = 0;
    st->neg_round = 0;
    st->sign_bit = 0;
    if (st->f_pres == 1)        //надо записать round в структуру
        st->round = st->wdth_pres;  //и удалить такую же операцию  в roundation
    else
        st->round = 6;
}

void 	circle(t_struct *st, t_sun eeei)
{
	int c;
	int b;

	for (c = (SIZE_M - st->shift); c < SIZE_M; c++)
	{
		if (c == (SIZE_M - st->shift))
		{
			eeei.v.mant & (1L << c) ? (b = 1) : (b = 0);
			if (b == 1 && c > 0)
				st->fp = sum_char(st->fp, st->arr, st);
			continue ;
		}
		if (c < 0)
		{
			two_degree(st);
			continue ;
		}
		eeei.v.mant & (1L << c) ? (b = 1) : (b = 0);
		two_degree(st);
		if (b == 1)
			st->fp = sum_char(st->fp, st->arr, st);
	}
}

void    bit_parcer(double f, t_struct *st)
{
    t_sun eeei;
    int c;

    eeei.f = f;
    init_chars(st);
    if (eeei.v.sign == 1)
        st->sign_bit = 1;
    c = check_zero(eeei, st);
    if (c == 1)
        return;
    st->shift = exp_shift(eeei);
    if (st->shift >= 0)
    {
    	circle(st, eeei);
        if (st->shift != 0)
			two_degree(st);
        st->fp = sum_char(st->fp, st->arr, st);
        st->fp = get_char(st->fp);
        ft_memdel(&st->arr);
    }
    else
        st->f_zero = 1;
    after_point(eeei, st);
    ft_out(st->fp, st->sp, st);
}

//    printf("%d_ %d_ %d  %.32f\n", eeei.v.sign, eeei.v.exp, eeei.v.mant, eeei.f);
//    printf("shift:%d\n", st->shift);
//    for (c = (SIZE_M - st->shift); c < SIZE_M; c++)
//        ft_putchar(eeei.v.mant & (1L << c) ? '1' : '0');
//    printf("\n");



//int two_degree(char *arr, int deg)
//{
//    int i;
//    int len;
//    char *newptr;
//
//    i = 0;
//    if (arr[i] == '\0')
//        arr[i] = '1';
//    i = ft_strlen(arr);
//    len = i;
//    while (deg > 0)
//    {
//        i--;
//        tmp = arr[i];
//        arr[i] += tmp - '0';
//        if (arr[i] > '9' && i == 0)
//        {
//            newptr = ft_strnew(len + 1);
//            fp[i]-= 10;
//            fp[i - 1]++;
//        }
//    }
//}


//for (c = (SIZE_M - st->shift); c < SIZE_M; c++)
//{
//if (c == (SIZE_M - st->shift))
//{
//eeei.v.mant & (1L << c) ? (b = 1) : (b = 0);
//if (b == 1)
//st->fp = sum_char(st->fp, arr);
//continue ;
//}
//if (c < 0)
//{
//arr = sum_char(arr, arr);
//continue ;
//}
//eeei.v.mant & (1L << c) ? (b = 1) : (b = 0);
//arr = sum_char(arr, arr);
//if (b == 1)
//st->fp = sum_char(st->fp, arr);
//}
//if (st->shift != 0)
//arr = sum_char(arr, arr);
//st->fp = sum_char(st->fp, arr);