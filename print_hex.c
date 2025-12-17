/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:01:36 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/12/17 20:36:21 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_digits(unsigned long nb, const char *base)
{
	int		count;
	char	ch;

	count = 0;
	if (nb >= 16)
	{
		count += print_hex_digits(nb / 16, base);
	}
	ch = base[nb % 16];
	write(1, &ch, 1);
	count++;
	return (count);
}

int	print_hex(unsigned int n, int uppercase)
{
	unsigned long	nb;
	const char		*base;

	nb = n;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (print_hex_digits(nb, base));
}
