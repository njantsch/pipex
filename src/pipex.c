/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:25 by njantsch          #+#    #+#             */
/*   Updated: 2023/07/05 18:40:41 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parent_process(t_pipex *s, char **av, char **envp, int *fd)
{
	int	out_file;

	out_file = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (out_file == -1)
		ft_error("Error trying to open file in parent process", s);
	dup2(fd[0], STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
	close(fd[1]);
	if (get_path(s, av[3], envp) == 1)
		ft_error("Input error (second command)", s);
	execve(s->path_to_file, s->args_parent, envp);
	ft_error("Error with execve function in parent process", s);
}

void	child_process(t_pipex *s, char **av, char **envp, int *fd)
{
	int	in_file;

	in_file = open(av[1], O_RDONLY, 0644);
	if (in_file == -1)
		ft_error("Error trying to open file in child process", s);
	dup2(fd[1], STDOUT_FILENO);
	dup2(in_file, STDIN_FILENO);
	close(fd[0]);
	if (get_path(s, av[2], envp) == 1)
		ft_error("Input error (first command)", s);
	execve(s->path_to_file, s->args_child, envp);
	ft_error("Error with execve function in child process", s);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	t_pipex	*s;

	if (ac == 5)
	{
		s = struc_init(av);
		if (!s)
			return (perror("Error creating struct\n"), 1);
		if (pipe(fd) == -1)
			return (1);
		pid1 = fork();
		if (pid1 == -1)
			ft_error("Error creating child process", s);
		if (pid1 == 0)
		{
			child_process(s, av, envp, fd);
			ft_terminate_struct(s);
		}
		parent_process(s, av, envp, fd);
		ft_terminate_struct(s);
	}
	else
		return (ft_printf("syntax error\n"), 1);
	return (0);
}
