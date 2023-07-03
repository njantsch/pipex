/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:02:25 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/19 21:04:28 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count += 1;
	if (n < 0)
		count += 1;
	while (n != 0)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

static int	into_pos(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

int	ft_print_number(int n)
{
	unsigned int	num;

	if (n < 0)
		if (ft_putchar('-') == -1)
			return (-1);
	num = into_pos(n);
	if (num >= 10)
	{
		if (ft_print_number(num / 10) == -1)
			return (-1);
		if (ft_print_number(num % 10) == -1)
			return (-1);
	}
	else
		if (ft_putchar(num + '0') == -1)
			return (-1);
	return (num_len(n));
}
