/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 13:37:28 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/01/16 11:23:29 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	print_character(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	convertor(const char specifier, va_list args)
{
	int	converted;

	converted = 0;
	if (specifier == 'c')
		converted += print_character(va_arg(args, int));
	else if (specifier == 's')
		converted += print_string(va_arg(args, char *));
	else if (specifier == 'p')
		converted += print_pointer(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		converted += print_digits(va_arg(args, int));
	else if (specifier == 'u')
		converted += print_udigits(va_arg(args, unsigned int));
	else if (specifier == 'x')
		converted += print_base(va_arg(args, unsigned int), 16, 0);
	else if (specifier == 'X')
		converted += print_base(va_arg(args, unsigned int), 16, 1);
	else if (specifier == '%')
		converted += print_character('%');
	else
		converted = -1;
	return (converted);
}

int	parser(const char *format, va_list args)
{
	int		i;
	int		bytes;
	int		converted;

	i = 0;
	bytes = 0;
	converted = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			converted = convertor(format[i], args);
			if (converted == -1)
				return (-1);
			bytes += converted;
		}
		else
			bytes += print_character(format[i]);
		i++;
	}
	return (bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes_down;

	bytes_down = 0;
	va_start(args, format);
	bytes_down = parser(format, args);
	if (bytes_down == -1)
		return (-1);
	va_end(args);
	return (bytes_down);
}
