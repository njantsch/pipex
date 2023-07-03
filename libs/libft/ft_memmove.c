/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:42:26 by njantsch          #+#    #+#             */
/*   Updated: 2023/03/30 12:24:37 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *) dst;
	source = (unsigned char *) src;
	if (dst == 0 && src == 0)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len--)
			dest[len] = source[len];
	}
	return (dest);
}
