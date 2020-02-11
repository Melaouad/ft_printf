/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaouad <melaouad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:25:54 by melaouad          #+#    #+#             */
/*   Updated: 2020/02/12 00:31:32 by melaouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

char		*reverse(char *str2, int i)
{
	char	*ch;
	int		j;

	ch = (char *)malloc(i);
	j = 0;
	i--;
	while (i >= 0)
	{
		ch[j] = str2[i];
		i--;
		j++;
	}
	ch[j] = '\0';
	free(str2);
	return (ch);
}
