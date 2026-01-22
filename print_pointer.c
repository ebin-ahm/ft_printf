/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:41:19 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/12/18 12:11:59 by ebin-ahm         ###   ########.fr       */
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

int	print_pointer(void *ptr)
{
	unsigned long	address;
	int				count;
	int				ret;

	address = (unsigned long)ptr;
	if (!ptr)
		return (ft_write("(nil)", 5));
	count = 0;
	ret = ft_write("0x", 2);
	if (ret == -1)
		return (-1);
	count += 2;
	if (address == 0)
	{
		ret = ft_write("0", 1);
		if (ret == -1)
			return (-1);
		return (count + 1);
	}
	ret = print_hex_digits(address, "0123456789abcdef");
	if (ret == -1)
		return (-1);
	return (count + ret);
}
