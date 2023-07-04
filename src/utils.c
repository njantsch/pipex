/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:01:39 by njantsch          #+#    #+#             */
/*   Updated: 2023/07/04 18:07:32 by njantsch         ###   ########.fr       */
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
	st->args_child = ft_split(av[2], ' ');
	st->args_parent = ft_split(av[3], ' ');
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
	ft_terminate_struct(s);
	perror(msg);
	exit(1);
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
