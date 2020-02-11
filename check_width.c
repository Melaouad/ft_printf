/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaouad <melaouad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:23:47 by melaouad          #+#    #+#             */
/*   Updated: 2020/02/12 00:30:12 by melaouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

t_str		*check_width(t_str *tab)
{
	int i;

	if (tab->format[tab->i] == '*')
	{
		tab->i++;
		i = va_arg(tab->ap, int);
		if (i < 0)
		{
			tab->flags[0] = '-';
			i = i * (-1);
		}
		tab->width = i;
	}
	else
	{
		while (tab->format[tab->i] >= '0' && tab->format[tab->i] <= '9')
		{
			tab->width *= 10;
			tab->width += (tab->format[tab->i] - 48);
			tab->i++;
		}
	}
	return (tab);
}
