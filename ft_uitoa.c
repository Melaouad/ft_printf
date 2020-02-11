/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaouad <melaouad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:25:11 by melaouad          #+#    #+#             */
/*   Updated: 2020/02/12 00:30:28 by melaouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		ft_lenth(unsigned int nb)
{
	int i;

	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_lenth(n);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len--;
	while (i <= len)
	{
		dest[len] = ((n % 10) + 48);
		n = n / 10;
		len--;
	}
	return (dest);
}
