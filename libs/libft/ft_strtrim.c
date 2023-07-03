/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:30:21 by njantsch          #+#    #+#             */
/*   Updated: 2023/03/31 15:04:35 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkf(char const *str1, char const *chs)
{
	int	front_len;

	front_len = 0;
	while (str1[front_len])
	{
		if (ft_strchr(chs, str1[front_len]) == NULL)
			break ;
		front_len++;
	}
	return (front_len);
}

static int	checkb(char const *string, char const *characters)
{
	int	back_len;
	int	count;

	count = 0;
	back_len = ft_strlen(string);
	if (back_len != 0)
	{
		while (string[back_len] >= 0)
		{
			if (ft_strchr(characters, string[back_len]) == NULL)
				break ;
			count++;
			back_len--;
		}
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	int		final_len;
	size_t	f_len;
	size_t	b_len;
	int		i;

	i = 0;
	b_len = checkb(s1, set);
	f_len = checkf(s1, set);
	final_len = ft_strlen(s1) - (f_len + b_len);
	if (f_len == ft_strlen(s1))
		return (ft_strdup(""));
	cpy = (char *)ft_calloc(final_len + 2, sizeof(char));
	if (!cpy)
		return (NULL);
	while (i <= final_len)
	{
		cpy[i] = s1[f_len];
		f_len++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
