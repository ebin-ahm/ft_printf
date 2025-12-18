/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:48:47 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/12/17 20:49:12 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_udigits(unsigned long nb)
{
	int		count;
	char	ch;

	count = 0;
	if (nb >= 10)
	{
		count += print_udigits(nb / 10);
	}
	ch = '0' + (nb % 10);
	write(1, &ch, 1);
	count++;
	return (count);
}

int	print_unsigned(unsigned int n)
{
	unsigned long	nb;
	int				count;
	char			ch;

	nb = n;
	count = 0;
	if (nb == 0)
	{
		ch = '0';
		write(1, &ch, 1);
		count++;
		return (count);
	}
	count += print_udigits(nb);
	return (count);
}
