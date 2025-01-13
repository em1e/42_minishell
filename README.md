<h1 align="center">
	📖 Minishell
</h1>

## Description
Minishell is a recreation of the popular Unix shell, `bash`, designed to help you understand how command-line interpreters work. With this shell, you can execute commands, handle piping (`|`), redirection (`>`), and environment variable management, mimicking the behavior of Bash. Additionally, it supports handling signals, handling `exit` commands, and more, making it a small but powerful shell.

This project provides a hands-on way to explore how a shell processes input, interprets commands, interacts with the operating system, and executes system calls.

***

[![minishell demo](https://i.ytimg.com/vi/w-UHjiFiuXQ/hqdefault.jpg)](https://youtu.be/w-UHjiFiuXQ "minishell demo")

## Features

- **Command Execution**: Execute basic commands such as `ls`, `echo`, `cat`, and more.
- **Pipes (`|`)**: Connect multiple commands via pipes to pass the output of one command as input to the next.
- **Redirection (`>`, `>>`, `<`)**: Redirect input and output between files and commands.
- **Environment Variables**: Set and get environment variables like `$PATH`, `$USER`, etc.
- **Signals**: Handle signals like `Ctrl-C` and `Ctrl-D` gracefully.
- **Customizable Prompt**: Customize the shell prompt and the appearance of the shell.
- **History**: Track and access previously run commands (optional feature, depending on your implementation).
- **Exit Command**: Exit the shell with the `exit` command.

## Compile and Run

### Installation

1. Clone the repository:

```shell
git clone <repository_url>
cd 42_minishell
```

2. To compile the program, simply run:

```shell
make
```

3. To run the program:

```shell
./minishell
```

## Controls
Simply type a command and press Enter to execute it.
Use Ctrl-C to interrupt the running command (handled gracefully in Minishell).
Use Ctrl-D to exit the shell (end of input).

### Example commands:
ls – List directory contents
echo "Hello World" – Print the string Hello World to the terminal
cat file.txt – Display contents of a file
exit – Exit the shell

```shell
./minishell
minishell$ echo "Hello, World!"
> Hello, World!
minishell$ ls
> Documents  Downloads  Minishell  Pictures
minishell$ cat file.txt
> This is the content of file.txt.
minishell$ exit
```

