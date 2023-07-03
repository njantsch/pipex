/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:02:55 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/29 14:01:50 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		len = 0;
		start = ft_strlen(s);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	dest = ft_calloc(len + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s + start, len + 1);
	return (dest);
}
