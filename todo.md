- Piece together new version of pipex. **DONE**
	- Find the new files in src. **DONE**
	- Change the header to include the corresponding new functions.i **DONE**
	- Change the makefile to include the new files. **DONE**

- Make a verbal (or visual) flowchart of pipeX.
	- Initial visual flowchart on paper. **DONE** (See photo on phone 21-03-25)
	- Revised flowchart after PipeX is "working".
	- Refined flowchart that is incorporated with refactoring.

- Write the main pipex function that checks whther each separate process has succeeded and if not returns the correct exit code (errno).
	[21 - 03 - 25] Initial prototype has been made. Most of the actual piping and opening/closing is done in create\_children.

- Norminette & refactor entire program.

- Write function that retrieves the exit status of a "failed" child using WIFEXITED and WEXITSTATUS.
- Add initial checking of infile and outfile permissions.
	- if files do not exist or have incorrect permissions, the pipe command can still continue correctly.
		for example: `< nonexistingfile cat | ls > outfile` will still work. An error will be printed to std\_err informing the user about a (non-critical) problem). If open(nonexistingfile) leads to -1 we can still continue, so we shouldn't exit.

- Initial checking whether the commands have actual commands. (./pipex "infile" "" "" "outfile")
