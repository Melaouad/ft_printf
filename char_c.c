/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaouad <melaouad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 23:58:51 by melaouad          #+#    #+#             */
/*   Updated: 2020/02/12 00:30:08 by melaouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void		char_c(t_str *tab)
{
	char print;

	print = va_arg(tab->ap, int);
	charc(tab, print);
}
