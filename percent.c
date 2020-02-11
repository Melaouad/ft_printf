/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaouad <melaouad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:25:41 by melaouad          #+#    #+#             */
/*   Updated: 2020/02/12 00:31:30 by melaouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void		percent(t_str *tab)
{
	char	*result;

	if (tab->tst_prec != '.' && tab->flags[1] == '0' && tab->flags[0] != '-')
	{
		tab->precision = tab->width;
		tab->width = 0;
		result = char_d(tab, 1, "%");
		tab->len = tab->len + ft_strlen(result);
		ft_putstr(result);
		free(result);
	}
	else
		charc(tab, tab->format[tab->i]);
}
