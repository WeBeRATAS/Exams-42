/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:45:24 by rbuitrag          #+#    #+#             */
/*   Updated: 2025/03/27 16:04:56 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

void	print_error(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	cd(char **av, int i)
{
	if (i != 2)
		return (print_error("error: cd: bad arguments\n"), 1);
	if (chdir(av[1]) == -1)
		return (print_error("error: cd: cannot change directory to"),\
				print_error(av[1]), print_error("\n"), 1);
	return (0);
}

void	set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || \
				close(fd[1]) == -1))
			print_error("error: fatal\n"), exit (1);
}

int	exec(char **av, int i, char **env)
{
	int has_pipe;
	int	fd[2];
	int pid;
	int	status;

	has_pipe = av[i] && !strcmp(av[i], "|");
		if (!has_pipe && !strcmp(*av, "cd"))
			return (cd(av, i));
		if (has_pipe && pipe(fd) == -1)
			print_error("error: fatal 01\n"), exit(1);
		if ((pid = fork()) == -1)
			print_error("error: fatal 02\n"), exit(1);
		if (!pid)
		{
			av = 0;
			set_pipe(has_pipe, fd, 1);
			if (!strcmp(*av, "cd"))
				exit (cd(av, i));
			execve(*av, av, env);
			print_error("error: cannot execute ");
			print_error(*av);
			print_error("\n");
			exit (1);
		}
	waitpid(pid, &status, 0);
	set_pipe(has_pipe, fd, 0);
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	int i;
	int status;

	i = 0;
	status = 0;
	while (av[i])
	{
		av += i + 1;
		i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (i)
			status = exec(av, i, env);
	}
	if (status)
		return (status);
	return (0);
}
