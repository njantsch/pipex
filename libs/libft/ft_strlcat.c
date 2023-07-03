/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:57:11 by njantsch          #+#    #+#             */
/*   Updated: 2023/03/30 13:03:10 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	i;
	size_t	size_src;
	size_t	size_dest;

	i = 0;
	size_src = ft_strlen(src);
	size_dest = ft_strlen(dest);
	j = size_src + size_dest;
	if (size == 0 || size <= size_dest)
		return (size_src + size);
	while (src[i] && size_dest < size - 1)
		dest[size_dest++] = src[i++];
	dest[size_dest] = '\0';
	return (j);
}
