/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_std_in_out.c                                  :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: terramint <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:32:53 by terramint         #+#    #+#             */
/*   Updated: 2025/03/27 14:04:13 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(int *in_out_file, int (*pfd)[2])
{
	if (in_out_file != NULL)
		close(*in_out_file);
	if (pfd != NULL)
	{
		close((*pfd)[0]);
		close((*pfd)[1]);
	}
}

int	setup_cmd(int *last_read_end)
{
	int	pfd[2];

	if (pipe(pfd) == -1)
	{
		close(*last_read_end);
		return (-1);
	}
	if (dup2(*last_read_end, 0) == -1)
	{
		close_fds(last_read_end, &pfd);
		return (-1);
	}
	close(*last_read_end);
	if (dup2(pfd[1], 1) == -1)
	{
		close_fds(NULL, &pfd);
		return (1);
	}
	close(pfd[1]);
	*last_read_end = pfd[0];
	return (0);
}

int	setup_first_cmd(int infile_fd, int *last_read_end)
{
	int	pfd[2];

	if (pipe(pfd) == -1)
	{
		close_fds(&infile_fd, NULL);
		return (-1);
	}
	if (dup2(infile_fd, 0) == -1 && infile_fd != -1)
	{
		close_fds(&infile_fd, &pfd);
		return (-1);
	}
	close_fds(&infile_fd, NULL);
	if (dup2(pfd[1], 1) == -1)
	{
		close_fds(NULL, &pfd);
		return (-1);
	}
	close(pfd[1]);
	*last_read_end = pfd[0];
	return (0);
}

int	setup_last_cmd(int outfile_fd, int *last_read_end)
{
	if (dup2(*last_read_end, 0) == -1)
	{
		close(*last_read_end);
		close(outfile_fd);
		return (-1);
	}
	close(*last_read_end);
	if (outfile_fd == -1)
		return (-1);
	if (dup2(outfile_fd, 1) == -1 && outfile_fd != -1)
	{
		close(outfile_fd);
		return (-1);
	}
	close(outfile_fd);
	return (0);
}

int	setup_std_in_out(int i, int cmd_c, char **argv, int *saved_fd)
{
	static int	infile_fd = -99;
	static int	outfile_fd = -99;

	if ((infile_fd == -99 || outfile_fd == -99) && argv != NULL)
	{
		infile_fd = open(argv[0], O_RDONLY);
		outfile_fd = open(argv[cmd_c + 1], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	}
	if (i == -1)
	{
		close(infile_fd);
		close(outfile_fd);
		close(*saved_fd);
		return (-1);
	}
	if (i == 0)
		return (setup_first_cmd(infile_fd, saved_fd));
	else if (i == cmd_c - 1)
		return (setup_last_cmd(outfile_fd, saved_fd));
	else
		return (setup_cmd(saved_fd));
}
