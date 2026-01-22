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

static int	add_count(int *count, int ret)
{
	if (ret == -1)
		return (-1);
	*count += ret;
	return (0);
}

static int	print_digits(long nb)
{
	char	c;
	int		ret;
	int		count;

	count = 0;
	if (nb >= 10)
	{
		ret = print_digits(nb / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = '0' + (nb % 10);
	ret = ft_write(&c, 1);
	if (ret == -1)
		return (-1);
	return (count + 1);
}

int	print_int(int n)
{
	long	nb;
	int		count;
	int		ret;

	nb = (long)n;
	count = 0;
	if (nb < 0)
	{
		ret = ft_write("-", 1);
		if (add_count(&count, ret) == -1)
			return (-1);
		nb = -nb;
	}
	if (nb == 0)
	{
		ret = ft_write("0", 1);
		if (add_count(&count, ret) == -1)
			return (-1);
		return (count);
	}
	ret = print_digits(nb);
	if (ret == -1)
		return (-1);
	return (count + ret);
}
