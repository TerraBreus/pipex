How to possible make multiple pipex?
Code would have to take in an amount of strings, and snip the first and last one for infile and outfile respectively.

Then we would have to call the pipe function for every (N - 1) amount of commands we get. Since the infile and outfile must be specified, the function will need atleast (N - 3) where N cannot be 0, so we will always need at least 4 commands total, if we count the program itself as an argument too, our argument counter would be a minimum of five. 
1. name of program
2. name of infile
3. name of first command
4. name of last command
5. name of outfile.

If we want to add multiple pipes, the structure would have a small difference;
1. name of program
2. name of infile
3. name of first command
.. name of cmdN...
4. name of last command
5. name of outfile

The number N can range from 0 to max. 
The idea behind it is that we have three different 'pipe' functions, the first one that reads from the infile and pipes the output of that to the input for the next command, the middle one that (if needed) reads from the input and writes to the output, and then finally the last pipe that reads from the input and write to the outfile.

The exit stati (octopi) have not benefit yet to my eye so I will leave them out. If someone can convince me otherwise, please do.

If we have N amount of extra strings (so apart from the first and last one)

--PIPES--
Make an array for (N + 1) pipes (since N is only extra)
If no extra strings are given, this function still returns a pointer to a pointer of a pipe (which is a little silly maybe but effective in all other scenarios).
If the array of pointers is a 2d matrix of 1x(N+2) where N is again the extra amount of cmds, its correct syntax should I believe be called as pfdv[0][0]/pfdv[0][1] for read/write respectively (or `*pfd[0] and *pfd[1]`).

With that in mind, let's have a look at how the code would 'flow'.

Read from infile and write to write-side of pipe.

-- -- -- -- --ONLY IF (N > 0)-- -- -- --
read from the read side of pipe and write to the next pipe
-- -- -- -- -- -- -- -- -- GO ON -- -- -- -- -- -- -- --

Read from the read side of pipe and write to the outfile.

This calls for three different functions
pipe-in
pipe-through
pipe-out

Pipe-through will only be called if the TOTAL argc >= 5.
An additional function will at the very start create the necessary pipes (minimal of 1).
```
if argc >= 5
	pipe-in argv[1] argv[2]
	pipe-through argv[i + 2]
	pipe-out argv[i + 3] argv[i + 4]

pipe-in();
	open infile (argv[1]) and dup2 to std-in
		open(infile)
		dup2(infile, 0)
		close (infile)
	dup pipe-write to stdout
		close(pipe-read)
		dup2(pipe-write, 1)
		close(pipe-write)
	fork to exec cmd1(argv[2])
		create flags and check for paths
pipe-through();
	//This part would need at least two pipes to function.
	pipe the read side to be std_in
		dup2(pipe-read, 0)
		close(pipe-read)
	pipe the write side of the NEXT PIPE to be std_out
		close(pipe-NEXT-read)		//syntax: close(pfd[N][0]
		dup2(pipe-NEXT-write, 1)	//	  dup2(pfd[N][1]
		close(pipe-NEXT-write)
	fork to exec and cmdN (argv[N + 2])
		yes.
pipe-out();
	go figure.

