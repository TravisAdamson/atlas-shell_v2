# Shellshocked - A shockingly good shell

_You have been Shellshocked!_

![Shellshocked](https://github.com/TravisAdamson/holbertonschool-simple_shell/blob/ed3c9c65ff0cf911db1742f439367f6d0a8b79af/Shellshockedneon.gif)

## Project Description

Shellshocked is a super cool shell program that allows you to execute commands and navigate through your system using a command-line interface. It provides a stylish and interactive shell experience with additional cool features to make your terminal sessions awesome!

## Table of Contents
1. [Project's Title](#shellshocked---a-shockingly-good-shell)
2. [Project Description](#project-description)
3. [Table of Contents](#table-of-contents)
4. [Main Components](#main-components)
5. [How to Install and Run the Project](#how-to-install-and-run-the-project)
6. [How to Use the Project](#how-to-use-the-project)
7. [Credits](#credits)
8. [License](#license)
9. [How to Contribute to the Project](#how-to-contribute-to-the-project)
10. [Tests](#tests)
11. [Include the GCC Used and Why](#include-the-gcc-used-and-why)
12. [Valgrind for Memory Leak Check](#valgrind-for-memory-leak-check)
13. [Show Examples of What It Does and the Features It Has](#show-examples-of-what-it-does-and-the-features-it-has)
14. [The Shell Can Run Any Command Specified by the User](#the-shell-can-run-any-command-specified-by-the-user)

## Main Components

1. `check_turtle`: This function checks whether a given file and/or directory exist. It returns -1 if the file doesn't exist, 0 if the directory doesn't exist, and 1 if both file and directory exist.

2. `shell_cracked`: This function is used for tokenizing the input string based on the specified delimiter(s). It returns the first token of the input.

3. `main`: The main function of the shell program. It runs in a loop, reading user input, parsing it, and executing commands. The user input is tokenized, and the command is executed with its arguments using `execve`. The `turtle_or_not` function is used to determine the correct directory path for the command to be executed.

4. `sleepy_turtle`: This function is used to read user input from the terminal. It reads characters from the standard input if the shell is running interactively.

5. `turtle_cross_road_or_not`: This function is responsible for launching the input command with its arguments as a child process using `fork` and `execve`.

6. `turtle_or_not`: This function checks if a given command exists in the current working directory or any of the directories listed in the PATH environment variable. It uses the `check_turtle` function to check for file existence.

7. `turtle_path`: This function extracts the value of the PATH environment variable.

8. `turtle_pen`: This function prints out all environmental variables.

9. `The header file `shellshocked.h` defines function prototypes and includes necessary header files.

## How to Install and Run the Project
1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Compile the project using GCC with cool flags for error checking and style:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

4. Run the shell:
./hsh

## How to Use the Project
1. Once the cool shell is running, you can enter commands as you would in a regular shell.
2. Shellshocked supports basic commands such as `ls`, `pwd`, `cd`, and more.
3. You can also use environmental variables by typing `$VAR_NAME` to access their values.
4. To exit the shell, use the `exit` command.

## Credits
Shellshocked is developed and maintained by Cool Developer Name (https://github.com/TravisAdamson/holbertonschool-simple_shell/blob/2cf0b1b590dc7a0437caaf17547e5b7920aad63b/AUTHORS).

## License
Shellshocked is licensed under the Cool MIT License (https://opensource.org/licenses/MIT).

## How to Contribute to the Project
1. Fork the repository.
2. Create a new branch: `git checkout -b feature/your-cool-feature-name`.
3. Make your changes and commit them: `git commit -m "Add your cool message here"`.
4. Push to the branch: `git push origin feature/your-cool-feature-name`.
5. Create a pull request.

## Tests
Shellshocked includes cool unit tests to ensure its functionalities are working correctly. To run the tests, use the following command:
make test

## Include the GCC Used and Why
The shell is compiled using the GCC compiler with the following cool flags for strict error checking and style:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Valgrind for Memory Leak Check
To check for memory leaks in the cool shell, use Valgrind with the following command:
valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./hsh

## Show Examples of What It Does and the Features It Has
Example 1: Running basic commands
$ ls
check_run.c README.md shellshocked.h turtle_path.c

Example 2: Running `ls` with flags
$ ls -la
total 56
drwxr-xr-x 2 root root 328 Aug 7 07:41 .
drwxr-xr-x 6 root root 4096 Aug 7 07:26 ..
-rw-r--r-- 1 root root 686 Aug 7 07:26 check_run.c
-rw-r--r-- 1 root root 1188 Aug 7 07:26 check_turtle.c
...

Example 3: Displaying the current working directory
$ pwd
/holbertonschool-simple_shell_remake/readme

Example 4: Echoing an environmental variable
$ echo SHELLSHOCKED
SHELLSHOCKED

## The Shell Can Run Any Command Specified by the User
You can run any cool command in the cool shell by providing its full path or if the command is in the PATH directory, you can just type the command name and press Enter. The cool shell will take care of the rest!

Enjoy the cool shell and have a blast with your terminal adventures! Happy hacking!
