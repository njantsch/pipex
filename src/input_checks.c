/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:20:33 by njantsch          #+#    #+#             */
/*   Updated: 2023/07/03 18:45:40 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//-------------------------------------------------//
// Function that manages all the checker functions //
//-------------------------------------------------//
int	checks(t_pipex *s, int ac, char **av, char **envp)
{
	if (get_path(s, ac, av, envp) == 1)
		return (1);
	return (0);
}

//-------------------------------------------------------------------//
// Gets the "PATH" variable from envp and checks if it exists and is //
// accessible														 //
//-------------------------------------------------------------------//
int	get_path(t_pipex *s, int ac, char **av, char **envp)
{
	int		i;
	int		j;
	char	*cmd;
	char	**path;

	i = 1;
	j = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0 && envp[i])
		i++;
	if (envp[i] == NULL)
		return (1);
	path = ft_split(envp[i] + 5, ':');
	i = 1;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j] && av[i][j] != ' ')
			j++;
		cmd = ft_substr(av[i], 0, j);
		if (check_path(s, path, cmd) == 1)
			return (free(cmd), free_prev_alloc(path), 1);
	}
	free(cmd);
	free_prev_alloc(path);
	return (0);
}

//-------------------------------------------------------------------------//
// First checks if the absolute path has been given as an argument, if not //
// it checks if the file (the command) exists                              //
//-------------------------------------------------------------------------//
int	check_path(t_pipex *s, char **path, char *cmd)
{
	int			i;
	static int	j;
	char		*cmd_path;

	i = 0;
	j = 0;
	if (access(cmd, F_OK) == 0)
		return (0);
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin_free(cmd_path, cmd);
		if (access(cmd_path, F_OK) == 0)
		{
			s->final_path[j] = cmd_path;
			j++;
			free(cmd_path);
			return (0);
		}
		free(cmd_path);
		i++;
	}
	return (1);
}
