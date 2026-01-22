/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:30:12 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/12/18 12:12:01 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *s)
{
	int	index;
	int	ret;

	index = 0;
	if (!s)
		return (ft_write("(null)", 6));
	while (s[index] != '\0')
	{
		ret = ft_write(&s[index], 1);
		if (ret == -1)
			return (-1);
		index++;
	}
	return (index);
}
