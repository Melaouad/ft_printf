/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaouad <melaouad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:23:21 by melaouad          #+#    #+#             */
/*   Updated: 2020/02/12 00:30:11 by melaouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str		*check_flags(t_str *tab)
{
	while (tab->format[tab->i] == '0' || tab->format[tab->i] == '-')
	{
		if (tab->format[tab->i] == '-')
			tab->flags[0] = '-';
		else if (tab->format[tab->i] == '0')
			tab->flags[1] = '0';
		tab->i++;
	}
	return (tab);
}
