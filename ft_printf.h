/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/05 21:13:57 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/01/16 10:56:49 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		print_character(const char c);
int		print_string(const char *string);
int		print_pointer(void *pointer);
int		print_digits(int num);
int		print_udigits(unsigned int num);
int		print_base(unsigned long num, int base, int uppercase);
int		convertor(const char specifier, va_list args);
int		parser(const char *format, va_list args);
int		ft_printf(const char *format, ...);

#endif
