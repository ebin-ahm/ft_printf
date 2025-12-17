/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:30:12 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/12/17 19:01:19 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *s)
{
	int	index;

	index = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[index] != '\0')
	{
		write(1, &s[index], 1);
		index++;
	}
	return (index);
}
