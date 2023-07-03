/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:08:15 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/03 15:55:24 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*given_node;
	t_list	*next_node;

	given_node = *lst;
	while (given_node != NULL)
	{
		(*del)(given_node->content);
		next_node = given_node->next;
		free (given_node);
		given_node = next_node;
	}
	*lst = NULL;
}
