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

int	ft_write(const void *buf, size_t n)
{
	ssize_t	ret;

	ret = write(1, buf, n);
	if (ret < 0)
		return (-1);
	return ((int)ret);
}

static int	handle_specifier(char spec, va_list *args)
{
	int	ret;

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
	ret = ft_write("%", 1);
	if (ret == -1)
		return (-1);
	ret = ft_write(&spec, 1);
	if (ret == -1)
		return (-1);
	return (2);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		ret;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			ret = handle_specifier(format[i], &args);
		}
		else
			ret = ft_write(&format[i], 1);
		if (ret == -1)
			return (va_end(args), -1);
		count += ret;
		i++;
	}
	va_end(args);
	return (count);
}
