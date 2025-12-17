/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:05:56 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/12/17 17:03:48 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_specifier(char spec, va_list *args)
{
	if (spec == 'c')
		return (print_char(va_arg(*args, int)));
	if (spec == 's')
		return (print_string(va_arg(*args, char *)));
	if (spec == 'd' || spec == 'i')
		return (print_int(va_arg(*args, int)));
	if (spec == 'u')
		return (print_unsigned(va_arg(*args, unsigned int)));
	if (spec == 'x')
		return (print_hex(va_arg(*args, unsigned int), 0));
	if (spec == 'X')
		return (print_hex(va_arg(*args, unsigned int), 1));
	if (spec == 'p')
		return (print_pointer(va_arg(*args, void *)));
	if (spec == '%')
		return (print_percent());
	return (write(1, "%", 1) + write(1, &spec, 1));
}

int	ft_printf(const char *format, ...)
{
	int		index;
	int		count;
	va_list	args;

	va_start(args, format);
	index = 0;
	count = 0;
	while (format && format[index])
	{
		if (format[index] == '%')
		{
			index++;
			if (format[index])
				count += handle_specifier(format[index], &args);
		}
		else
		{
			write(1, &format[index], 1);
			count++;
		}
		index++;
	}
	va_end(args);
	return (count);
}
