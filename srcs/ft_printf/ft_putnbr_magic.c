/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_magic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:51:04 by lboulang          #+#    #+#             */
/*   Updated: 2022/11/28 21:37:03 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digit(long long int n, int base_len)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n >= base_len)
	{
		n = n / base_len;
		len++;
	}
	return (len);
}

int	ft_putnbr_magic(long long int nbr, char *base, int count)
{
	long long int	nb;
	int				base_len;

	nb = nbr;
	base_len = ft_strlen(base);
	if (count == 0)
		count = ft_count_digit(nb, base_len);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb < base_len)
		ft_putchar(base[nb]);
	else
	{
		ft_putnbr_magic(nb / base_len, base, count);
		ft_putnbr_magic(nb % base_len, base, count);
	}
	return (count);
}
