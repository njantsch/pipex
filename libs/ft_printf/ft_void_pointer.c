/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:41:17 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/19 18:26:00 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_len(size_t num)
{
	int	count;

	count = 0;
	if (num == 0)
		count++;
	while (num != 0)
	{
		count++;
		num /= 16;
	}
	return (count);
}

static int	ft_ptr_in_hex(size_t num)
{
	if (num >= 16)
	{
		ft_ptr_in_hex(num / 16);
		ft_ptr_in_hex(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
	return (ptr_len(num));
}

int	ft_void_pointer(size_t ptr)
{
	int	len;

	len = 2;
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (ptr == 0)
		len += ft_putchar('0');
	else
		len += ft_ptr_in_hex(ptr);
	return (len);
}
