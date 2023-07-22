# Simple Shell

## Introduction
A shell is computer program that exposes an operating system's services to ahuman user or other programs. It is named a shell because it is the outermost layer around the operating systems.
The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.

### Context
Write a simple UNIX command interpreter.

### Learning Objectives
#### General
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C     programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the dirfference between a function and system call
- How to create processes
- What are the three prototypes of main
- How does the shell use `the PATH` to find the programs
- How to execute another program with the `execve` system call
- How to suspend the executtion of a process until one of its children term    inates
- What is `EOF` / "end-of-file"?

## Requirements
### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using th    e options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All your files should end with a new line
- Your code should use the `Betty` style. It will be checked using `betty-s    tyle.pl` and `betty-doc.pl`
- Your shell should not have any memory leaks
- All your header files should be include guarded

## More Info
### List of allowed functions and system calls

- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

## Compilation
Your shell will be compiled this way:

```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh```

### Testing
Your shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
 
But also in non-interactive mode:
```$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Tasks
- Tasks 0
`Write a beautiful code that passes the Betty checks`
- Task 1
` Write a UNIX command line interpreter.`
- Tast 2
` Handle command lines with arguments.`
- Task 3 
` Handle the PATH`
` fork must not be called if the command doesn't exist.`
- Task 4
` Implement the exit built-in, that exits the shell.`
- Task 5
`Implement the env built-in, that prints the current environment.`

### Reference
