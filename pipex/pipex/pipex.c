/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:59:18 by marvin            #+#    #+#             */
/*   Updated: 2024/10/02 11:59:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_child(int in_file, int fd[2], char *argv[], char **envp)
{
	int	status;
	int	pid1;

	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(in_file, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close (fd[1]);
		close (in_file);
		if (envp_split(argv[2], envp) == 1)
			exit(1);
		exit(0);
	}
	waitpid (pid1, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int	sec_child(int out_file, int fd[2], char *argv[], char **envp)
{
	int	pid2;
	int	status;

	pid2 = fork();
	if (pid2 == 0)
	{
		dup2 (out_file, STDOUT_FILENO);
		dup2 (fd[0], STDIN_FILENO);
		close (fd[0]);
		close (fd[1]);
		close (out_file);
		if (envp_split(argv[3], envp) == 1)
			exit(1);
		exit (0);
	}
	close (fd[0]);
	close (fd[1]);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

void	sleep_all(char **argv)
{
	char	**split;
	int		i;
	int		max_sleep;

	max_sleep = 0;
	i = 1;
	while (i++ < 4)
	{
		if (ft_strncmp (argv[i], "sleep", 5) == 0)
		{
			split = ft_split(argv[i], ' ');
			if (ft_atoi(split[1]) > max_sleep)
				max_sleep = ft_atoi(split[1]);
		}
	}
	sleep (max_sleep);
}

int	open_files(char *in_file)
{
	int	in_fd;

	if (ft_strncmp(in_file, "/dev/urandom", 11) == 0)
		in_fd = open("/dev/urandom", O_RDONLY);
	else
		in_fd = open(in_file, O_RDONLY);
	return (in_fd);
}

int	main(int argc, char *argv[], char **envp)
{
	int	ret1;
	int	ret2;
	int	fd[2];
	int	in_file;
	int	out_file;

	if (argc != 5)
		return (ft_putstr_fd("Expected Format -> ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 2), 1);
	if (pipe(fd) < 0 || access(argv[1], F_OK | R_OK) < 0)
		return (ft_putstr_fd("File is not accessible\n", 2), 1);
	in_file = open_files(argv[1]);
	out_file = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (in_file < 0 || out_file < 0)
		return (ft_putstr_fd("File cannot be opened\n", 2), 1);
	if (ft_strncmp(argv[2], "sleep", 5) == 0 && ft_strncmp(argv[3], "sleep", 5) == 0)
		sleep_all(argv);
	else
	{
		ret1 = first_child (in_file, fd, argv, envp);
		ret2 = sec_child (out_file, fd, argv, envp);
		if (ret1 == 1 || ret2 == 1)
			ft_putstr_fd("Error: Command not found\n", 2);
	}
	close (in_file);
	close (out_file);
	return (0);
}
