/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 13:38:57 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/01/16 11:45:53 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(const char *string)
{
	int		len;

	if (string == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(string);
	write(1, string, len);
	return (len);
}

int	print_pointer(void *pointer)
{
	int				len;
	unsigned long	n;

	if (pointer == NULL)
	{
		len = write(1, "(nil)", 5);
		return (len);
	}
	n = (unsigned long)pointer;
	len = print_string("0x");
	len += print_base(n, 16, 0);
	return (len);
}

int	print_digits(int num)
{
	int		len;
	long	n;

	len = 0;
	if (num < 0)
	{
		len += print_character('-');
		n = (long)num * -1;
	}
	else
		n = (long)num;
	if (n == 0)
		len += print_character('0');
	else if (n > 0 && n < 10)
		len += print_character(n + '0');
	else if (n >= 10)
	{
		len += print_digits(n / 10);
		len += print_character(n % 10 + '0');
	}
	return (len);
}

int	print_udigits(unsigned int num)
{
	int		len;

	len = 0;
	if (num == 0)
		len += print_character('0');
	else if (num < 10)
		len += print_character(num + '0');
	else
	{
		len += print_udigits(num / 10);
		len += print_character(num % 10 + '0');
	}
	return (len);
}

int	print_base(unsigned long num, int base, int uppercase)
{
	int		len;
	char	*hex_digits;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	len = 0;
	if (num == 0)
		len += print_character('0');
	else if (num > 0 && num < (unsigned)base)
		len += print_character(hex_digits[num]);
	else
	{
		len += print_base(num / base, base, uppercase);
		len += print_character(hex_digits[num % base]);
	}
	return (len);
}
