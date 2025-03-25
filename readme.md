# Abstract
UNIX pipe operator simulated in C using systemcalls as part of school42 curriculum.

*systemcalls used in this project*
```
access(), open(), close(), pipe(), execve(), dup2(), wait(), exit()
```

# ToC
- Abstract.
- Table of Contents.
- Introduction. **WIP**
	- A few remarks on writing your own code.
- Key concepts. **WIP**
	- The pipe operator (`|`).
	- A brief summary of file descriptors.
	- Systemcalls.
		- piping()
		- duping()
		- forking()
		- execve()
- Visual flowchart of Pipex. **WIP**
- Verbal flowchart of PipeX. **WIP**
	- Error handling.
		- How to handle exit codes.
		- perror() & strerror(): your new best friends.
	- Piping from in to out.
		- Duping stdin and stdout to the correct pipe file descriptors.
	- Closing and freeing.
		- Considerations on readability, functionality and (memory-)efficiency.
- Pseudocode. **WIP**
- Considerations in retrospect. **WIP**
- Addendum
	- todo.md

# Introduction.
If you are somewhat experienced in UNIX-based systems, there is a high chance you have used pipes before. In short, pipes allow you to redirect the output of a function as the input of another function. Not only does this save you a lot of copy-pasting, it also allows for multiple functions to run at the same time while having the output of the prior function flow to the input of the other (this still feels like magic to me as my knowledge of systemcalls is still limited).

As part of the school42 curriculum you have the option of either doing `Minitalk` or `PipeX`. Further down the line when writing minishell, much of the PipeX project can be used. I therefore used this oppurtunity to take my time on doing the bonus and making the code as readable and usable for future projects (in general this should be good practice anyway).

### A few remarks on the Paced System, chatGPT and writing your own code.
When I joined CODAM (part of the school42 network) in October 2024 we were the first cohort (at CODAM) under the paced system. This system automizes implementing deadlines for students which allows CODAM to take in more students (since before, staff would have to manually implement and keep track of all student's deadlines). However, as with all automazation, the individual gets lost in the crowd as authenticity get replaced by conformity. Especially now with the rapid infestation of large language models, the student no longer has to read endless pages of manuals written fourty years ago or sit on a problem for days on end. This has of course many benefits and I in no way claim to oppose the usage of LLM's. However I fear that the Paced System, combined with AI, emphasises results instead of the process. The student is stimulated/pressured to copy thoughtprocesses of others instead of learning how to write (and constantly rewrite!) code by themselves. 

If you want to truly understand and master the process of writing programs, I believe you have to 'learn how to learn'. This is different for many people but I am rather sure that all approaches have one universal; creating. As much as I am a fond supporter of Open Source Code, I believe you should write your own code and, if you have the time and energy, even 'meta' your code by externalizing your thoughts along the way.

**I therefore encourage you to use this Github page as an example of *how* to write code. Not as a repository for you to copy. WRITE YOUR OWN CODE!!!**

Yes, you will get stuck a lot and potentially even question whether you want to become a software engineer in the first place. But you will learn how to learn which will not only make you write unique (and possibly groundbreaking) code but also make you a more skilled programmer (and in my opinion a stronger human being).

As a wise man said;

`Give me a fish and I shall eat for a day. Teach me how to fish and I shall eat for the rest of my life.`

Similarly;

`Show me some code and I shall code for a day. Teach me how to code and I shall code for the rest of my life.` 

# Visual flowchart of PipeX

# Verbal flowchart of PipeX

# Pseudocode
Before writing the actual code, it often helps to write pseudocode. Not only will you get a better overview and understanding of your program but you may run into possible problems or solutions that failed to come to mind when thinking of the overal structure of your program.

There are many ways of writing pseudocode. In this particular instance, a choice was made to almost immediately simulate the actual code as better practice and to help foreshadow possible problems with the prototypes of all functions.
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

# Considerations in retrospect.
# Addendum
- (todo)[todo.md]

