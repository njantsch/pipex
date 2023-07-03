/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_in_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:17:57 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/19 19:51:27 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(unsigned int num)
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

int	ft_num_in_hex(unsigned int num, char c)
{
	if (num >= 16)
	{
		if (ft_num_in_hex(num / 16, c) == -1)
			return (-1);
		if (ft_num_in_hex(num % 16, c) == -1)
			return (-1);
	}
	else
	{
		if (num < 10)
		{
			if (ft_putchar(num + '0') == -1)
				return (-1);
		}
		else
		{
			if (c == 'x')
				if (ft_putchar(num - 10 + 'a') == -1)
					return (-1);
			if (c == 'X')
				if (ft_putchar(num - 10 + 'A') == -1)
					return (-1);
		}
	}
	return (num_len(num));
}
