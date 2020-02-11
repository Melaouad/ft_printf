/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaouad <melaouad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:24:18 by melaouad          #+#    #+#             */
/*   Updated: 2020/02/12 00:30:16 by melaouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int			ft_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

int			ft_printf(const char *frmt, ...)
{
	t_str	*tab;

	if (!(tab = (t_str*)malloc(sizeof(t_str))))
		return (-1);
	tab->format = frmt;
	tab->len = 0;
	tab->i = 0;
	if (frmt)
	{
		va_start(tab->ap, frmt);
		tab->len = check(tab);
		va_end(tab->ap);
	}
	free(tab);
	return (tab->len);
}
