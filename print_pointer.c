/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:41:19 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/12/17 20:42:51 by ebin-ahm         ###   ########.fr       */
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

int	print_pointer(void *ptr)
{
	unsigned long	address;
	int				count;

	address = (unsigned long)ptr;
	count = 0;
	write(1, "0x", 2);
	count += 2;
	if (address == 0)
	{
		write(1, "0", 1);
		count++;
		return (count);
	}
	count += print_hex_digits(address, "0123456789abcdef");
	return (count);
}
