/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaouad <melaouad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:23:54 by melaouad          #+#    #+#             */
/*   Updated: 2020/02/12 00:30:13 by melaouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check(t_str *tab)
{
	if (ft_strcmp(tab->format, "%") == 0)
		return (-1);
	while (tab->format[tab->i] != '\0')
	{
		if (tab->format[tab->i] == '%')
		{
			tab->i++;
			tab->width = 0;
			tab->precision = -1;
			tab->flags = (char *)malloc(2);
			tab->flags[0] = '\0';
			tab->flags[1] = '\0';
			tab->value_d = 0;
			tab->tst_prec = '\0';
			tab->prec_neg = 0;
			specification(tab);
		}
		else
		{
			ft_putchar(tab->format[tab->i]);
			tab->len++;
		}
		tab->i++;
	}
	return (tab->len);
}
