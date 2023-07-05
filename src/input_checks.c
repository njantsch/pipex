/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:20:33 by njantsch          #+#    #+#             */
/*   Updated: 2023/07/05 17:52:41 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//-------------------------------------------------------------------//
// Gets the "PATH" variable from envp and checks if it exists and is //
// accessible														 //
//-------------------------------------------------------------------//
int	get_path(t_pipex *s, char *arg, char **envp)
{
	int		i;
	char	*cmd;
	char	**path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0 && envp[i])
		i++;
	if (envp[i] == NULL)
		return (1);
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	if (!arg)
		return (1);
	while (arg[i] && arg[i] != ' ')
		i++;
	cmd = ft_substr(arg, 0, i);
	if (check_path(s, path, cmd) == 1)
		return (free(cmd), free_prev_alloc(path), 1);
	return (free(cmd), free_prev_alloc(path), 0);
}

//-------------------------------------------------------------------------//
// First checks if the absolute path has been given as an argument, if not //
// it checks if the file (the command) exists                              //
//-------------------------------------------------------------------------//
int	check_path(t_pipex *s, char **path, char *cmd)
{
	int			i;
	char		*cmd_path;

	i = 0;
	if (access(cmd, F_OK | X_OK) == 0)
	{
		s->path_to_file = ft_strdup(cmd);
		return (0);
	}
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin_free(cmd_path, cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			s->path_to_file = ft_strdup(cmd_path);
			return (free(cmd_path), 0);
		}
		free(cmd_path);
		i++;
	}
	return (1);
}
