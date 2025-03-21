/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_std_in_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terramint <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:32:53 by terramint         #+#    #+#             */
/*   Updated: 2025/03/20 19:23:33 by terramint        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void close_fds(int *in_out_file, int (*pfd)[2])
{
	if (in_out_file != NULL)
		close(*in_out_file);
	if (pfd != NULL)
	{
		close((*pfd)[0]);
		close((*pfd)[1]);
	}
}

int	setup_first_cmd(int infile_fd, int *last_read_end)
{
	int	pfd[2];

	if (pipe(pfd) == -1)
	{
		close_fds(&infile_fd, NULL);
		return (-1);
	}
	if (dup2(infile_fd, 0) == -1)
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
	if (dup2(outfile_fd, 1) == -1)
	{
		close(outfile_fd);
		return (-1);
	}	
	close(outfile_fd);
	return (0);
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

int	setup_std_in_out(int cmd_i, int cmd_c, int infile_fd, int outfile_fd)
{
	static int	last_read_end;

	if (cmd_i == 0)
		return (setup_first_cmd(infile_fd, &last_read_end));
	else if (cmd_i == cmd_c - 1)
		return (setup_last_cmd(outfile_fd, &last_read_end));
	else
		return (setup_cmd(&last_read_end));
}
