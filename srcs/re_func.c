#include "../includes/ft_printf.h"

int	re_putstr(char const *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	re_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}