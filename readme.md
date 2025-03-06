#P i p e X
***multiple pipes possible***
UNIX pipe operator simulated in C using systemcalls.
**Systemcalls used:**
- open()
- close()
- pipe()
- execve()
- dup2()
- wait()

# NOTES
- `sleep 3 | sleep 3` takes three seconds to finish since both commands are executed 'at the same time'.

## Pseudocode
```
int	check_for_errors(int argc, char *infile, char *outfile, char *envp[])
		if (argc < 5)						// ./pipex [infile] [cmd_1] [cmd_2] [cmd_n] [outfile]
			return (usage(), 1);
		if (check_file_permissions() == -1)			//infile: F_OK && R_OK. outfile: if F_OK -> W_OK
			return (1);
									//NB: Create outfile if non-existent.
									//if outfile-created change create_outfile to TRUE
		if (paths = find_path_in_envp() == NULL)		//NULL if malloc failure or no path;
			return (1);

int	setup_std_in_out(cmd_i, cmd_c, infile_fd, outfile_fd)		//redirect I/O so that execve() writes/reads to pipe/file
		static int	last_read_end;
		
		if (cmd_i == 0) 					//from infile to pipe_write
			if (pipe() == -1)
				close(infile);				
				return (1);
			if (dup2(infile, 0) == -1) 			//redirect std_in to infile
				close(pipe_write);
				close(pipe_read);
				close(infile);
				return (1);
			close(infile);
			if (dup2(pipe_write, 1) == -1) 			//redirect std_out to write end of pipe
				close(pipe_write);
				close(pipe_read);
				return (1);
			close(pipe_write);
			last_read_end = pipe_read;
		if (cmd_i == cmd_c - 1) 				//from pipe_read to outfile
			if (dup2(last_read_end, 0) == -1)		//redirect std_in to "previous" pipe
				close(outfile);
				close(last_read_end);
				return (1);
			close(last_read_end);
			if (dup2(outfile, 1) == -1)			//redirect std_out to outfile
				close(outfile);
				return (1);
			close(outfile);
		else							//all pipes in between
			if (pipe() == -1)
				close(last_read_end);
				return (1);
			if (dup2(last_read_end, 0) == -1)		//redirect std_in to "previous" pipe
				close(pipe_read);
				close(pipe_write);
				close(last_read_end);
				return (1);
			close(last_read_end);
			if (dup2(pipe_write, 1) == -1)			//redirect std_out to write end of pipe
				close(pipe_read);
				close(pipe_write);
				return (1);
			close(pipe_write);
			last_read_end = pipe_read;
		return (0);

int	exec_cmd()
	if (cmd_and_flags = split(cmd, ' ') == NULL)			//NULL if malloc failure
		return (1);
	if (paths = find_possible_paths(envp) == NULL)			//NULL if malloc failure or wrong envp
		free(cmd_and_flags);
		return (1);
	if (path_to_cmd = find_path(paths, cmd_and_flags[0]) == NULL)	//NULL if malloc failure or no path found
		free(paths);
		free(cmd_and_flags);
		return (1);
	execve(path_to_cmd, cmd_and_flags, envp)			//envp to replicate environment config.
	free(paths)
	free(cmd_and_flags)
	return (1);							//only executed if execve fails.

int	cmd_pipe(cmd_c, ++argv, envp)
		open(infile);						//arg[0] since we skip program name.
		if (infile_fd == -1)
			return (1);
		open(outfile);						//arg[cmd_c + 1] (+1 for infile)
		if (outfile_fd == -1)
			close(infile);
			return (1);
		while (i < cmd_c)
			if (setup_std_in_out(i) == 1)			//We will be printing to std_err. To be safe, close I/O.
				close(0);
				close(1);
				close(infile);
				close(outfile);
				return (1);
			int pid_t = fork();
			if (pid_t == -1)				//What to do in case of fork-failure?
				return (1);
			if (pid_t == 0)
				if (exec_cmd(arg[i + 1], envp) == 1)	//Find and pass command to execve
					close_all();
					exit(EXIT_FAILURE);
			i++;
		close(1);
		close(0);
		wait();							//wait for all children to finish.
		return (WEXITSTATUS)					//Return exitstatus of last child.
```
