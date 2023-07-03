/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:16:11 by njantsch          #+#    #+#             */
/*   Updated: 2023/03/31 12:54:28 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (count + 2);
	if (num < 0)
		count += 1;
	while (num != 0)
	{
		num /= 10;
		count += 1;
	}
	return (count + 1);
}

static char	*negative(int neg)
{
	int		i;
	char	*str1;
	int		sign;
	int		temp;

	sign = -1;
	str1 = malloc(get_len(neg));
	if (str1 == NULL || get_len(neg) == 0)
		return (NULL);
	i = get_len(neg) - 1;
	str1[i] = '\0';
	while (i >= 0)
	{
		if (i == 0)
		{
			str1[i] = '-';
			break ;
		}
		temp = sign * (neg % 10);
		str1[--i] = temp + '0';
		neg /= 10;
	}
	return (str1);
}

static char	*positive(int pos)
{
	int		i;
	char	*str2;

	str2 = malloc(get_len(pos));
	if (str2 == NULL || get_len(pos) == 0)
		return (NULL);
	i = get_len(pos) - 1;
	str2[i] = '\0';
	while (i-- > 0)
	{
		str2[i] = (pos % 10) + '0';
		pos /= 10;
	}
	return (str2);
}

char	*ft_itoa(int n)
{
	if (n < 0)
		return (negative(n));
	return (positive(n));
}
