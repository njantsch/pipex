/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:09:01 by njantsch          #+#    #+#             */
/*   Updated: 2023/07/03 17:41:46 by njantsch         ###   ########.fr       */
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
	char	**final_path;
	char	**args_child;
	char	**args_parent;
}	t_pipex;

int		checks(t_pipex *s, int ac, char **av, char **envp);
int		get_path(t_pipex *s, int ac, char **av, char **envp);
int		check_path(t_pipex *s, char **path, char *cmd);

t_pipex	*struc_init(char **av);
void	free_prev_alloc(char **buff);

void	parent_process(t_pipex *s, char **av, char **envp, int *fd);
void	child_process(t_pipex *s, char **av, char **envp, int *fd);

#endif
