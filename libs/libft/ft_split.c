/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:05:22 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/29 14:01:41 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char sep)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			count++;
			while (str[i] != sep && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	free_alloc(char **buff, size_t index)
{
	size_t	j;

	j = 0;
	while (j < index)
	{
		free(buff[j]);
		j++;
	}
	free(buff);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	size_t	index;
	size_t	i;
	size_t	j;

	index = 0;
	i = -1;
	j = 0;
	buffer = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!buffer || !s)
		return (NULL);
	while (++i <= ft_strlen(s) && s[i])
	{
		if (s[i] == c)
			index++;
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
		{
			buffer[j++] = ft_substr(s, index, (i - index) + 1);
			if (buffer[j - 1] == NULL)
				return (free_alloc(buffer, j), NULL);
			index = i + 1;
		}
	}
	buffer[j] = NULL;
	return (buffer);
}
