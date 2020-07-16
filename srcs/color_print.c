/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <efleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:00:01 by efleta            #+#    #+#             */
/*   Updated: 2020/03/06 16:35:43 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	proverka(char *format, t_struct *st)
{
	int i;

	i = 0;
	st->i++;
	st->color = ft_memalloc(20);
	while (format[st->i] != '}')
	{
		st->color[i] = format[st->i++];
		i++;
	}
	st->i++;
	color_print(st);
}


void	color_print(t_struct *st)
{	
	if (ft_strcmp(st->color, "Blue") == 0)
		re_putstr("\033[1;34m");
	if (ft_strcmp(st->color, "Magenta") == 0)
		re_putstr("\033[1;35m");
	if (ft_strcmp(st->color, "Cyan") == 0)
		re_putstr("\033[1;36m");
	if (ft_strcmp(st->color, "Red") == 0)
	 	re_putstr("\033[1;31m");
	if (ft_strcmp(st->color, "Green") == 0)
		re_putstr("\033[1;32m");
	if (ft_strcmp(st->color, "eoc") == 0)
		re_putstr("\033[0m");
}