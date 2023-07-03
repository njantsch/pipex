/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:49:10 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/19 19:57:49 by njantsch         ###   ########.fr       */
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
		num /= 10;
	}
	return (count);
}

int	ft_print_unsigned(unsigned int num)
{
	if (num >= 10)
		if (ft_print_unsigned(num / 10) == -1)
			return (-1);
	if (ft_putchar(num % 10 + '0') == -1)
		return (-1);
	return (num_len(num));
}
