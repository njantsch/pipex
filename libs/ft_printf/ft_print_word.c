/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:31:55 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/19 18:12:59 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_print_string(char *str)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	if (!str)
	{
		check = write (1, "(null)", 6);
		return (check);
	}
	while (str[i])
	{
		check = write(1, &str[i], 1);
		if (check == -1)
			return (check);
		i++;
	}
	return (i);
}
