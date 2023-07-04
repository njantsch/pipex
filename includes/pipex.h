/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:09:01 by njantsch          #+#    #+#             */
/*   Updated: 2023/07/04 18:03:33 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../libs/libs.h"

typedef struct Pipex
{
	char	*path_to_file;
	char	**args_child;
	char	**args_parent;
}	t_pipex;

int		get_path(t_pipex *s, char *arg, char **envp);
int		check_path(t_pipex *s, char **path, char *cmd);

t_pipex	*struc_init(char **av);
void	free_prev_alloc(char **buff);
void	ft_error(char *msg, t_pipex *s);
void	ft_terminate_struct(t_pipex *s);

void	parent_process(t_pipex *s, char **av, char **envp, int *fd);
void	child_process(t_pipex *s, char **av, char **envp, int *fd);

#endif
