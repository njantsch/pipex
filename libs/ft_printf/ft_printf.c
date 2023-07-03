/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:21:57 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/20 10:57:57 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_sign(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_print_string(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		len += ft_print_number(va_arg(args, int));
	else if (c == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == '%')
		len += ft_putchar('%');
	else if (c == 'p')
		len += ft_void_pointer(va_arg(args, size_t));
	else if (c == 'x' || c == 'X')
		len += ft_num_in_hex(va_arg(args, unsigned int), c);
	return (len);
}

int	print_loop(const char *format, va_list args)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_check_sign(format[i], args);
			i++;
		}
		else
		{
			len += ft_putchar(format[i]);
			i++;
		}
		if (len == -1)
			break ;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		numb_of_ch;

	if (!format)
		return (-1);
	va_start(args, format);
	numb_of_ch = print_loop(format, args);
	va_end(args);
	return (numb_of_ch);
}

// #include <stdio.h>
// int main(void)
// {
// 	int i;
// 	int j;

// 	i = ft_printf("%d\n", -2147483648);
// 	printf("Implemented return: %d\n", i);
// 	j = printf("%d\n", -2147483648);
// 	printf("Original return: %d\n", j);
// 	system("leaks a.out");
// 	return (0);
// }
