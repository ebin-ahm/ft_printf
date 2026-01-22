/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:08:50 by ebin-ahm          #+#    #+#             */
/*   Updated: 2025/12/17 18:29:32 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_write(const void *buf, size_t n);

int	print_char(int c);
int	print_hex(unsigned int n, int uppercase);
int	print_int(int n);
int	print_percent(void);
int	print_pointer(void *ptr);
int	print_string(char *s);
int	print_unsigned(unsigned int n);

#endif
