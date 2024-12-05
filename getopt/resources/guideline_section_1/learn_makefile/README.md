**Introduction**
A makefile is a set of commands (similar to terminal commands) with variable names and targets to create object file and to remove them. You can compile your program any number of times by using makefile. The main idea of this file is to specify the dependencies.

The `make` utility is what is used to process the instructions written in the makefile.

```sh
make makefile
```

**How to create a Makefile**
1. Create a file called `Makefile`
2. Define Targets and Rules within the file:
	* Targets: These are the names of tasks you want to build, like "all", "clean", "compile", etc
	* Rules: These are the instructions for how to create or update a target. A rule consists of a target, prerequisites, and commands.
3. Write Rules
Example:
```make
# Rule for compiling the C program
main: main.c
	gcc -o main main.c
```
In this example:
`main` is the target.
`main.c` is the prerequisite (source code file).
`gcc -o main main.c` is the command to compile "main.c" into an executable named "main".
4. Run the `make` command
```sh
make
```

__________________________________
In this tutorial we will create 4 files:
1. `client.c` file: contains the main function
2. `server.c` file: contains the user defined function
3. `server.h` file: header file which calls the user defined functions in the server.c file
4. `makefile`: contains set of all the commands with their variable names.

A Makefile consists of a set of rules. A rule generally looks like this:
```sh
targets: prerequisites
	command
	command
	command
```
