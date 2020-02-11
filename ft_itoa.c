/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaouad <melaouad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:24:06 by melaouad          #+#    #+#             */
/*   Updated: 2020/02/12 00:30:17 by melaouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		ft_len(int nb)
{
	int i;

	i = 1;
	if (nb < 0)
	{
		nb = nb * (-1);
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		n = n * (-1);
		dest[i] = '-';
		i++;
	}
	dest[len] = '\0';
	len--;
	while (i <= len)
	{
		dest[len] = ((n % 10) + 48);
		n = n / 10;
		len--;
	}
	return (dest);
}
