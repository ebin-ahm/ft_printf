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
	int		ret;
	char	ch;

	count = 0;
	if (nb >= 10)
	{
		ret = print_udigits(nb / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ch = '0' + (nb % 10);
	ret = ft_write(&ch, 1);
	if (ret == -1)
		return (-1);
	return (count + 1);
}

int	print_unsigned(unsigned int n)
{
	unsigned long	nb;
	int				ret;
	char			ch;

	nb = n;
	if (nb == 0)
	{
		ch = '0';
		return (ft_write(&ch, 1));
	}
	ret = print_udigits(nb);
	return (ret);
}
