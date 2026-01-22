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
	int		ret;
	char	ch;

	count = 0;
	if (nb >= 16)
	{
		ret = print_hex_digits(nb / 16, base);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ch = base[nb % 16];
	ret = ft_write(&ch, 1);
	if (ret == -1)
		return (-1);
	return (count + 1);
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
		return (ft_write("0", 1));
	return (print_hex_digits(nb, base));
}
