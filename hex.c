/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaouad <melaouad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:25:25 by melaouad          #+#    #+#             */
/*   Updated: 2020/02/12 00:30:29 by melaouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdlib.h>

int			check_len(unsigned int nb)
{
	int		i;

	i = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

char		*hexedecimal(unsigned int nb, char c)
{
	char		*result;
	int			i;
	int			modl;
	int			len;

	len = check_len(nb);
	modl = 0;
	result = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		modl = nb % 16;
		if (modl < 10)
			result[i++] = modl + 48;
		else
			result[i++] = modl + c - 33;
		nb = nb / 16;
	}
	result[i] = '\0';
	result = reverse(result, ft_strlen(result));
	return (result);
}

void		hex_x(t_str *tab, char ch)
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
	nbr_str = hexedecimal(nbr, ch);
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
	nbr_len = 0;
	nbr = 0;
}
