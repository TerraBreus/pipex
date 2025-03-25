# Create Alpha version of PipeX (DONE)
- Piece together new version of pipex. **DONE**
	- Find the new files in src. **DONE**
	- Change the header to include the corresponding new functions.i **DONE**
	- Change the makefile to include the new files. **DONE**

# Flowchart
- Make a verbal (or visual) flowchart of pipeX.
	- Initial visual flowchart on paper. **DONE** (See photo on phone 21-03-25)
	- Revised flowchart after PipeX is "working".
	- Refined flowchart that is incorporated with refactoring.

- Write function that retrieves the exit status of a "failed" child using WIFEXITED and WEXITSTATUS.

# Fix Exit codes (DONE-ISH?)
- Write the main pipex function that checks whther each separate process has succeeded and if not returns the correct exit code (errno).
	[21 - 03 - 25] Initial prototype has been made. Most of the actual piping and opening/closing is done in create\_children.

# Norminette
- Norminette & refactor entire program.

# Initial checks
- Add initial checking of infile and outfile permissions.
	- if files do not exist or have incorrect permissions, the pipe command can still continue correctly.
		for example: `< nonexistingfile cat | ls > outfile` will still work. An error will be printed to std\_err informing the user about a (non-critical) problem). If open(nonexistingfile) leads to -1 we can still continue, so we shouldn't exit.

- Initial checking whether the commands have actual commands. (./pipex "infile" "" "" "outfile")

# Incorporate Douwe's necessary changes
- Fix pipex.c
	- :47 -> while loop must only wait for succesful forks. 
	- :51 -> wait() does not necessarily work in a linear way. If for some reason, there are still children running even though `finished_pid == last_pid`, you have created a zombie.
		- Douwe states this might be fixable if we use waitpid() to check the return status of the last process_id before we enter the while loop.
- Fix create\_children.c
	- :25 -> 0644 should be 0666. You want to give it maximum permission (without executable as that makes no sense). the umask settings will remove anything that is not allowed.
	- :36 -> Use the macros `STDIN_FILENO` and `STDOUT_FILENO` for portability.
- Fix exec\_cmd.c
	- :41 -> if, for some reason `paths = NULL` you have to pass the path to `execve()` with the command only. (`return (addendum)`). Only if you have a path parameter and you could not find the command should you print the error message.
	- :51 -> `ft_strncmp("some_string", NULL, 5)` will result in a segfault. You should loop the other way around. `while (envp[++i] != NULL && envp != NULL)` -> `if (ft_strncmp(jkahsd) == 0) { possibe_paths}`.
	- :55 -> If no path parameter is found, we do not have an error necessarily. You should pass the command simply as the addendum. I
	- :96 -> If `execve()` fails, it might be usefull to print some kind of an error message to `STDERR_FILENO`.
- Fix `set_up_std_in_out.c`
	- :18 -> If you the actual file descriptors (so pointers instead of copying the value), you might as well set them to -1 to prevent double closing. (don't forget to check whether the file descriptor is -1 before closing)

