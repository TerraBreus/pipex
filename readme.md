# Abstract
UNIX pipe operator simulated in C using systemcalls as part of school42 curriculum.

*systemcalls used in this project*
```
access(), open(), close(), pipe(), execve(), dup2(), wait(), exit()
```

# ToC
- [Abstract.](#abstract)
- [Table of Contents.](#toc)
- [Introduction.](#introduction) **WIP**
	- [A few remarks on writing your own code](#a-few-remarks-on-writing-your-own-code)
- [Key concepts.](#key-concepts) **WIP**
	- The pipe operator (`|`).
	- A brief summary of file descriptors.
	- Systemcalls.
		- piping()
		- duping()
		- forking()
		- execve()
- [Visual flowchart of Pipex.](#visual-flowchart-of-pipex) **WIP**
- [Verbal flowchart of PipeX.](#verbal-flowchart-of-pipex) **WIP**
	- Error handling.
		- How to handle exit codes.
		- perror() & strerror(): your new best friends.
	- Piping from in to out.
		- Duping stdin and stdout to the correct pipe file descriptors.
	- Closing and freeing.
		- Considerations on readability, functionality and (memory-)efficiency.
- [Pseudocode.](pseudocode.md) **WIP**
- [Considerations in retrospect.](#considerations-in-retrospect) **WIP**
- [Addendum](#addendum)
	- todo.md

# Introduction.
If you are somewhat experienced in UNIX-based systems, there is a high chance you have used pipes before. In short, pipes allow you to redirect the output of a function as the input of another function. Not only does this save you a lot of copy-pasting, it also allows for multiple functions to run at the same time while having the output of the prior function flow to the input of the other (this still feels like magic to me as my knowledge of systemcalls is still limited).

As part of the school42 curriculum you have the option of either doing `Minitalk` or `PipeX`. Further down the line when writing minishell, much of the PipeX project can be used. I therefore used this oppurtunity to take my time on doing the bonus and making the code as readable and usable for future projects (in general this should be good practice anyway).

### A few remarks on writing your own code
When I joined CODAM (part of the school42 network) in October 2024 we were the first cohort (at CODAM) under the paced system. This system automizes implementing deadlines for students which allows CODAM to take in more students (since before, staff would have to manually implement and keep track of all student's deadlines). However, as with all automazation, the individual gets lost in the crowd as authenticity get replaced by conformity. Especially now with the rapid infestation of large language models, the student no longer has to read endless pages of manuals written fourty years ago or sit on a problem for days on end. This has of course many benefits and I in no way claim to oppose the usage of LLM's. However I fear that the Paced System, combined with AI, emphasises results instead of the process. The student is stimulated/pressured to copy thoughtprocesses of others instead of learning how to write (and constantly rewrite!) code by themselves. 

If you want to truly understand and master the process of writing programs, I believe you have to 'learn how to learn'. This is different for many people but I am rather sure that all approaches have one universal; creating. As much as I am a fond supporter of Open Source Code, I believe you should write your own code and, if you have the time and energy, even 'meta' your code by externalizing your thoughts along the way.

**I therefore encourage you to use this Github page as an example of *how* to write code. Not as a repository for you to copy. WRITE YOUR OWN CODE!!!**

Yes, you will get stuck a lot and potentially even question whether you want to become a software engineer in the first place. But you will learn how to learn which will not only make you write unique (and possibly groundbreaking) code but also make you a more skilled programmer (and in my opinion a stronger human being).

As a wise man said;

`Give me a fish and I shall eat for a day. Teach me how to fish and I shall eat for the rest of my life.`

Similarly;

`Show me some code and I shall code for a day. Teach me how to code and I shall code for the rest of my life.` 

# Key Concepts.

# Visual flowchart of PipeX

# Verbal flowchart of PipeX

# Pseudocode
Before writing the actual code, it often helps to write pseudocode. Not only will you get a better overview and understanding of your program but you may run into possible problems or solutions that failed to come to mind when thinking of the overal structure of your program.

There are many ways of writing pseudocode. In this particular instance, a choice was made to almost immediately simulate the actual code as better practice and to help foreshadow possible problems with the prototypes of all functions.
click [here](pseudocode.md) to go to pseudocode file.
# Considerations in retrospect.
# Addendum
- [todo.md](todo.md)

