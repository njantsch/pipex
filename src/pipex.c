/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:25 by njantsch          #+#    #+#             */
/*   Updated: 2023/07/03 18:41:50 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parent_process(t_pipex *s, char **av, char **envp, int *fd)
{
	int	out_file;

	out_file = open(av[4], O_RDWR | O_CREAT, 0777);
	if (out_file == -1)
		perror("Error trying to open file in parent process\n");
	dup2(fd[0], STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
	close(fd[1]);
	if (execve(s->final_path[1], s->args_parent, envp) == -1)
		perror("Error executing the command (in execve function parent_p)\n");
}

void	child_process(t_pipex *s, char **av, char **envp, int *fd)
{
	int	in_file;

	in_file = open(av[1], O_RDONLY, 0777);
	if (in_file == -1)
		perror("Error trying to open file in child process\n");
	dup2(fd[1], STDOUT_FILENO);
	dup2(in_file, STDIN_FILENO);
	close(fd[0]);
	if (execve(s->final_path[0], s->args_child, envp) == -1)
		perror("Error executing the command (in execve function child_p)\n");
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
		if (checks(s, ac, av, envp) == 1)
			return (perror("Error with input\n"), 1);
		if (pipe(fd) == -1)
			return (1);
		pid1 = fork();
		if (pid1 == 0)
			child_process(s, av, envp, fd);
		waitpid(pid1, NULL, 0);
		parent_process(s, av, envp, fd);
	}
	else
		return (ft_printf("syntax error\n"), 1);
	return (0);
}
