/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsinged_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaouad <melaouad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:26:14 by melaouad          #+#    #+#             */
/*   Updated: 2020/02/12 00:31:35 by melaouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void		unsigned_u(t_str *tab)
{
	int				nbr_len;
	char			*nbr_str;
	char			*result;
	unsigned int	nbr;

	if (tab->tst_prec != '.' && tab->flags[1] == '0' && tab->flags[0] != '-')
	{
		tab->precision = tab->width;
		tab->width = 0;
	}
	nbr = va_arg(tab->ap, unsigned int);
	nbr_str = ft_uitoa(nbr);
	nbr_len = ft_strlen(nbr_str);
	if (tab->precision == 0 && nbr == 0)
		nbr_str[0] = '\0';
	if (tab->width == 1 && nbr == 0 && tab->precision == 0)
		tab->width_1 = 1;
	result = char_d(tab, nbr_len, nbr_str);
	tab->len = tab->len + ft_strlen(result);
	ft_putstr(result);
	free(nbr_str);
	free(result);
	nbr = 0;
	nbr_len = 0;
}
