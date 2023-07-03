/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:01:39 by njantsch          #+#    #+#             */
/*   Updated: 2023/07/03 18:46:12 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipex	*struc_init(char **av)
{
	t_pipex	*st;

	st = malloc(sizeof(t_pipex));
	st->final_path = malloc(sizeof(char *) * 3);
	st->args_child = ft_split(av[2], ' ');
	st->args_parent = ft_split(av[3], ' ');
	return (st);
}

void	free_prev_alloc(char **buff)
{
	size_t	j;

	j = 0;
	while (buff[j] != NULL)
	{
		free(buff[j]);
		j++;
	}
	free(buff);
}
