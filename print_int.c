/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:14:23 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/12/17 19:44:27 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_digits(long nb)
{
	int		count;
	char	ch;

	count = 0;
	if (nb >= 10)
		count += print_digits(nb / 10);
	ch = '0' + (nb % 10);
	write(1, &ch, 1);
	count++;
	return (count);
}

int	print_int(int n)
{
	long	nb;
	int		count;
	char	ch;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		ch = '-';
		write(1, &ch, 1);
		count++;
		nb = -nb;
	}
	if (nb == 0)
	{
		ch = '0';
		write(1, &ch, 1);
		count++;
		return (count);
	}
	count += print_digits(nb);
	return (count);
}
