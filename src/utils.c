/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:01:39 by njantsch          #+#    #+#             */
/*   Updated: 2023/07/05 18:31:08 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//------------------------------------------------------//
// Initializes and allocates the elements in the struct //
// and the struct itself                                //
//------------------------------------------------------//
t_pipex	*struc_init(char **av)
{
	t_pipex	*st;

	st = malloc(sizeof(t_pipex));
	if (!st)
		return (NULL);
	st->args_child = ft_split(av[2], ' ');
	if (!st->args_child)
		return (free(st), NULL);
	st->args_parent = ft_split(av[3], ' ');
	if (!st->args_parent)
		return (free_prev_alloc(st->args_child), free(st), NULL);
	return (st);
}

//-----------------------------------------------------//
// Frees all previously allocated memory in a 2D array //
//-----------------------------------------------------//
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

//---------------------------------------------------------//
// A function that destroys the struct and all of it's     //
// contents, prints an error message and exits the program //
//---------------------------------------------------------//
void	ft_error(char *msg, t_pipex *s)
{
	perror(msg);
	ft_terminate_struct(s);
	exit(EXIT_FAILURE);
}

//--------------------------------------------------------------//
// A function that destroys the struct and all of it's contents //
//--------------------------------------------------------------//
void	ft_terminate_struct(t_pipex *s)
{
	free_prev_alloc(s->args_child);
	free_prev_alloc(s->args_parent);
	free(s->path_to_file);
	free(s);
}
