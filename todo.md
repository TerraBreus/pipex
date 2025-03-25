# Create Alpha version of PipeX (DONE)
- Piece together new version of pipex. **DONE**
	- Find the new files in src. **DONE**
	- Change the header to include the corresponding new functions.i **DONE**
	- Change the makefile to include the new files. **DONE**

# Fix Exit codes (DONE-ISH?)
- Write the main pipex function that checks whther each separate process has succeeded and if not returns the correct exit code (errno).
	[21 - 03 - 25] Initial prototype has been made. Most of the actual piping and opening/closing is done in create\_children.
- Retrieve the exit status of a "failed" child using WIFEXITED and WEXITSTATUS. **DONE**

# Incorporate Douwe's necessary changes
- Fix pipex.c
	- :47 -> while loop must only wait for succesful forks. 
	- :51 -> wait() does not necessarily work in a linear way. If for some reason, there are still children running even though `finished_pid == last_pid`, you have created a zombie.
		- Douwe states this might be fixable if we use waitpid() to check the return status of the last process_id before we enter the while loop.
```
waitpid(last_pid, &status, 0); \\Wait for the last process to finish.
while (i < commands_executed)
{
	\\Wait for all other processes to finish.
	wait(NULL);
	i++;
}
if (WIFEXIT(last_pid) == 1)
	return (WIFEXITSTATUS(last_pid))
return (0);
```
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

# Add error messages.
- Whenever a systemcall fails, it would be usefull to print an error message so we know something went wrong.
# Initial checks
- Add initial checking of infile and outfile permissions.
	- if files do not exist or have incorrect permissions, the pipe command can still continue correctly.
		for example: `< nonexistingfile cat | ls > outfile` will still work. An error will be printed to std\_err informing the user about a (non-critical) problem). If open(nonexistingfile) leads to -1 we can still continue, so we shouldn't exit.

- Initial checking whether the commands have actual commands. (./pipex "infile" "" "" "outfile")

# Incorporate potential errors according to michmos' 42\_PIPEX\_TESTER
**We are simulating the pipex operator. Exit codes should therefore be identical to the actual pipe operator. (in bash for personal preference and convenience)**
[42\_PIPEX\_TESTER](https://github.com/michmos/42_pipex_tester) made by the amazing [michmos](https://github.com/michmos)

An example to check the exit status:
```
bash 
< infile_without_permissions cat -e | cat -e > outfile
echo ${PIPESTATUS[0]}
```
(*To check all elements use `@` instead of `0`.*)

- Program should have a three second execution time. (as of writing (22-05-2025) it has zero seconds execution time...)
	- **NB: ./pipex "infiles/basic.txt" "ls" "sleep 3" "outfiles/outfile" does execute for three seconds** 
```
./pipex "infiles/basic.txt" "sleep 3" "ls" "outfiles/outfile" 
< infiles/basic.txt sleep 3 | ls > outfiles/outfile_tester
```
- Program seems to have an incorrect exit code.
```
./pipex "infiles/infile_without_permissions" "cat -e" "cat -e" "outfiles/outfile"
< infiles/infile_without_permissions cat -e | cat -e > outfiles/outfile_tester
```
- Leaks!
```
./pipex "infiles/basic.txt" "nonexistingcommand" "cat -e" "outfiles/outfile"
./pipex "infiles/basic.txt" "cat -e" "nonexistingcommand" "outfiles/outfile" 
```
- Wrong exit status. (should be 127).
```
./pipex "infiles/basic.txt" "cat -e" "nonexistingcommand" "outfiles/outfile"
```
- timeouts if outfile has no permissions.
```
./pipex "infiles/basic.txt" "cat -e" "cat -e" "outfiles/outfile_without_permissions"
```
- Program experiences a 'deadlock situation' with the following input:
`./pipex "infiles/big_text.txt" "cat" "head -2" "outfiles/outfile"`

This is likely due to the second command finishing after two lines, therefore closing the read end of the pipe even though cat is still trying to write, therefore it never correctly ends.

It might be possible that if we first fork and afterwards call `set_up_std_in_out` the problem is resolved. As of now we first set up std_in_out and fork later.

# Norminette
- Norminette & refactor entire program.

# Update `readme.md`
- Make a verbal (or visual) flowchart of pipeX.
	- Initial visual flowchart on paper. **DONE** (See photo on phone 21-03-25)
	- Revised flowchart after PipeX is "working".
	- Refined flowchart that is incorporated with refactoring.


