# Shellshocked - A shockingly good shell

_You have been Shellshocked!_

![Shellshocked](https://github.com/TravisAdamson/atlas-shell_v2/blob/244524fc8a13d7d9b136b90635453d26dc408146/ShellShocked2.gif)

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
14. [The Shell Main Components and the Explanations](#the-shell-Main-Components-and-the-Explanations)


## Main Components

1. `check_turtle`: This function checks whether a given file and/or directory exist. It returns -1 if the file doesn't exist, 0 if the directory doesn't exist, and 1 if both file and directory exist.
2. `turtle_does`: This function executes a command with its arguments.
3. `turn_right`: This function redirects the standard output to a file, truncating the file if it already exists.
4. `right_uturn`: This function redirects the standard output to a file, appending to the file if it already exists.
5. `turn_left`: This function redirects the standard input from a file.
6. `turtle_homing`: This function executes commands based on operators present in the input.
7. `turtle_nap`: This function executes a command without waiting for its completion.
8. `turtle_current`: This function sets up and executes pipelines.
9. `current_length`: This function counts the number of pipes in the command line input.
10. `handle_turtle_interrupt`: This function handles SIGINT signal.
11. `_calloc`: Allocates memory for an array with malloc.
12. `_memcpy`: Copies n bytes of src to dest.
13. `_realloc`: Reallocates memory and copies memory to the new allocation.
14. `turtle_environment`: This function sets up the environment for the shell.
15. `rehome_turtle`: This function changes the current working directory of the shell.
16. `cd_assist`: This function assists in changing directories.
17. `view_nest`: This function prints out the current shell environment.
18. `turtle_is_free`: This function checks if a command is available in the shell environment.
19. `change_nest`: This function updates a shell environment variable.
20. `clear_nest`: This function clears a shell environment variable.
21. `turtle_cross_road_or_not`: This function launches a command with its arguments as a child process.
22. `empty_turtle_shell`: This function checks if the shell input is empty.
23. `turtle_surgery`: This function handles the execution of shell commands.
24. `feed_the_turtle`: This function reads user input from the terminal.
25. `env_load`: This function loads the shell environment.
26. `env_free`: This function frees the shell environment.
27. `_strcat`: This function concatenates two strings.
28. `_strcmp`: This function compares two strings.
29. `_strncmp`: This function compares two strings up to a specified length.
30. `_strcpy`: This function copies a string.
31. `_str_len`: This function calculates the length of a string.
32. `_strdup`: This function duplicates a string.
33. `_strsep`: This function tokenizes a string.
34. `_strcspn`: This function calculates the length of the initial segment of str1 that consists of characters not in str2.
35. `str_concat`: This function concatenates two strings.
36. `_getenv`: This function retrieves the value of an environment variable.
37. `_isdigit`: This function checks if a character is a digit.
38. `_atoi`: This function converts a string to an integer.
39. `find_mate`: This function finds a command in the shell environment.
40. `clear_debris`: This function removes redundant characters from a string.
41. `find_nest`: This function finds the shell environment.
42. `turtles_nest`: This function creates a shell environment.
43. `turtle_eggs`: This function executes shell commands.
44. `free_strvec`: This function frees memory allocated to a string vector.
45. `set_turtle_free_or_not`: This function sets the shell environment.
46. `baby_turtles`: This function tokenizes a string.
47. `make_turtlets`: This function creates a new shell environment.
48. `make_turtlet`: This function creates a new shell environment.
49. `no_such_turtle`: This function handles command not found errors.
50. `left_uturn`: This function redirects the standard input from a file.

## How to Install and Run the Project
1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Compile the project using GCC with cool flags for error checking and style:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
4. Run the shell:
```
./hsh
```

## To access the manual page for your Shellshocked shell, use the man command followed by the name of your shell:
1. Navigate to the project directory.
2. sudo cp man_1_hsh.1 /usr/share/man/man1/
3. sudo mandb
4. man man_1_hsh

man shellshocked

## How to Use the Project
1. Once the cool shell is running, you can enter commands as you would in a regular shell.
2. Shellshocked supports basic commands such as `ls`, `pwd`, `cd`, and more.
3. You can also use environmental variables by typing `$VAR_NAME` to access their values.
4. To exit the shell, use the `exit` command.

## Credits
Shellshocked is developed and maintained by Cool Developers:
matternstsr matthew.ernst@atlasschool.com
Travis travis.adamson@atlasschool.com
([GitHub](https://github.com/TravisAdamson/atlas-shell_v2/blob/main/AUTHORS.md)).

## License
Shellshocked is licensed under the Cool MIT License ([MIT](https://opensource.org/licenses/MIT)).

## How to Contribute to the Project
1. Fork the repository.
2. Create a new branch: `git checkout -b feature/your-cool-feature-name`.
3. Make your changes and commit them: `git commit -m "Add your cool message here"`.
4. Push to the branch: `git push origin feature/your-cool-feature-name`.
5. Create a pull request.

## Tests
Shellshocked includes cool unit tests to ensure its functionalities are working correctly. To run the tests, use the following command:
```
make test
```

## Include the GCC Used and Why
The shell is compiled using the GCC compiler with the following cool flags for strict error checking and style:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Valgrind for Memory Leak Check
To check for memory leaks in the cool shell, use Valgrind with the following command:
```
valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./hsh
```

## Show Examples of What It Does and the Features It Has
Example 1: Running basic commands
```
$ ls
turtle_cross_road_or_not.c turtle_environment.c turtle_gps.c turtle_homing.c turtle_interrupt.c turtle_memmory.c
```

Example 2: Running `ls` with flags

```
$ ls -la
total 324
drwxrwxrwx 1 mattie mattie  4096 Jun  3 18:03 .
drwxrwxrwx 1 mattie mattie  4096 Jun  3 17:33 ..
-rwxrwxrwx 1 mattie mattie  3221 Jun  3 17:11 turtle_cross_road_or_not.c
-rwxrwxrwx 1 mattie mattie  4768 Jun  3 17:33 turtle_environment.c
-rwxrwxrwx 1 mattie mattie  2211 Jun  3 17:11 turtle_gps.c
-rwxrwxrwx 1 mattie mattie  2460 Jun  3 17:11 turtle_homing.c
-rwxrwxrwx 1 mattie mattie   288 Jun  3 17:11 turtle_interrupt.c
-rwxrwxrwx 1 mattie mattie  1564 Jun  3 17:11 turtle_memmory.c
...
```

Example 3: Displaying the current working directory
```
$ pwd
/atlas-shell_v2/readme
```

Example 4: Echoing an environmental variable
```
$ echo SHELLSHOCKED
SHELLSHOCKED
```

## The Shell Can Run Any Command Specified by the User
You can run any cool command in the cool shell by providing its full path or if the command is in the PATH directory, you can just type the command name and press Enter. The cool shell will take care of the rest!

Enjoy the cool shell and have a blast with your terminal adventures! You will be shocked at what you can do!

<br/><br/><br/><br/>

# Additional Operation Info:


## The Shell Main Components and the Explanations

### 1. check_turtle
- **Description:** This function checks whether a given file and/or directory exist. It returns -1 if the file doesn't exist, 0 if the directory doesn't exist, and 1 if both file and directory exist.
- **Functionality:** This function first checks if the provided file or directory exists by using the `access` system call. If the file or directory exists, it returns 1. If only the file exists, it returns 0. If neither the file nor the directory exists, it returns -1.

### 2. turtle_does
- **Description:** This function executes a command with its arguments.
- **Functionality:** This function first parses the command line input to separate the command and its arguments. Then, it uses the `fork` system call to create a child process. In the child process, it uses the `execve` system call to execute the command with its arguments.

### 3. turn_right
- **Description:** This function redirects the standard output to a file, truncating the file if it already exists.
- **Functionality:** This function first opens the specified file for writing using the `open` system call, specifying the `O_WRONLY` and `O_CREAT` flags. Then, it uses the `dup2` system call to duplicate the file descriptor for standard output (`stdout`) to the file descriptor associated with the opened file. If the file already exists, it truncates its contents.

### 4. right_uturn
- **Description:** This function redirects the standard output to a file, appending to the file if it already exists.
- **Functionality:** This function first opens the specified file for writing using the `open` system call, specifying the `O_WRONLY`, `O_CREAT`, and `O_APPEND` flags. Then, it uses the `dup2` system call to duplicate the file descriptor for standard output (`stdout`) to the file descriptor associated with the opened file. If the file already exists, it appends its contents.

### 5. turn_left
- **Description:** This function redirects the standard input from a file.
- **Functionality:** This function first opens the specified file for reading using the `open` system call, specifying the `O_RDONLY` flag. Then, it uses the `dup2` system call to duplicate the file descriptor for standard input (`stdin`) to the file descriptor associated with the opened file.

### 6. turtle_homing
- **Description:** This function executes commands based on operators present in the input.
- **Functionality:** This function first parses the command line input to identify any operators such as pipes (`|`), redirection (`>`, `>>`, `<`), or background execution (`&`). It then uses a combination of the other functions to execute the commands accordingly, setting up pipelines, redirecting standard input and output, and handling background processes as needed.

### 7. turtle_nap
- **Description:** This function executes a command without waiting for its completion.
- **Functionality:** This function is similar to `turtle_does`, but it does not wait for the child process to complete before returning to the shell prompt. It uses the `fork` system call to create a child process and the `execve` system call to execute the command with its arguments in the child process, while the parent process continues to wait for user input.

### 8. turtle_current
- **Description:** This function sets up and executes pipelines.
- **Functionality:** This function first parses the command line input to identify and separate multiple commands connected by pipes (`|`). It then uses the `pipe` system call to create a pipe for each pair of commands. It creates child processes for each command in the pipeline, setting up input and output redirection using the `dup2` system call to connect the output of one command to the input of the next command in the pipeline. Finally, it executes each command using the `execve` system call.

### 9. current_length
- **Description:** This function counts the number of pipes in the command line input.
- **Functionality:** This function iterates through the command line input character by character, counting the occurrences of the pipe (`|`) character. It returns the total count of pipes found.

### 10. handle_turtle_interrupt
- **Description:** This function handles SIGINT signal.
- **Functionality:** This function sets up a signal handler for the SIGINT signal using the `signal` function. When the SIGINT signal is received (e.g., when the user presses Ctrl+C), the signal handler is called, and the shell prints a new prompt instead of terminating the program.

### 11. _calloc
- **Description:** Allocates memory for an array with malloc.
- **Functionality:** This function allocates memory for an array of elements, each with a size of `size` bytes. It initializes the allocated memory to zero using the `memset` function and returns a pointer to the allocated memory.

### 12. _memcpy
- **Description:** Copies n bytes of src to dest.
- **Functionality:** This function copies `n` bytes from the memory area pointed to by `src` to the memory area pointed to by `dest`. It returns a pointer to the destination memory area (`dest`).

### 13. _realloc
- **Description:** Reallocates memory and copies memory to the new allocation.
- **Functionality:** This function changes the size of the memory block pointed to by `ptr` to `size` bytes. If the reallocation is successful, it copies the existing data from the old memory block to the new memory block. If the reallocation fails, it returns `NULL`. It returns a pointer to the reallocated memory block.

### 14. turtle_environment
- **Description:** Sets up the environment for the shell.
- **Functionality:** This function initializes the shell environment by setting up environment variables such as `PATH` and `HOME`. It also initializes other variables and data structures used by the shell.

### 15. rehome_turtle
- **Description:** Changes the current working directory of the shell.
- **Functionality:** This function changes the current working directory of the shell to the directory specified by the `path` parameter using the `chdir` system call.

### 16. cd_assist
- **Description:** Assists in changing directories.
- **Functionality:** This function handles changing directories by calling the `chdir` system call. It handles special cases such as changing to the home directory (`cd` without arguments) and changing to the previous directory (`cd -`).

### 17. view_nest
- **Description:** Prints out the current shell environment.
- **Functionality:** This function displays the current shell environment, including environment variables and their values.

### 18. turtle_is_free
- **Description:** Checks if a command is available in the shell environment.
- **Functionality:** This function searches the shell environment for the specified command and returns true if the command is found, otherwise false.

### 19. change_nest
- **Description:** Updates a shell environment variable.
- **Functionality:** This function updates the value of the specified environment variable in the shell environment.

### 20. clear_nest
- **Description:** Clears a shell environment variable.
- **Functionality:** This function removes the specified environment variable from the shell environment.

### 21. turtle_cross_road_or_not
- **Description:** Launches a command with its arguments as a child process.
- **Functionality:** This function uses the `fork` system call to create a child process, and the `execve` system call to execute the specified command with its arguments in the child process.

### 22. empty_turtle_shell
- **Description:** Checks if the shell input is empty.
- **Functionality:** This function checks if the shell input consists only of whitespace characters (spaces, tabs, newlines, etc.). If the input is empty or contains only whitespace, it returns true; otherwise, it returns false.

### 23. turtle_surgery
- **Description:** Handles the execution of shell commands.
- **Functionality:** This function first checks if the command is a built-in command (e.g., `cd`, `exit`). If it is a built-in command, it executes the command using the corresponding built-in function. If it is not a built-in command, it executes the command using the `turtle_cross_road_or_not` function.

### 24. feed_the_turtle
- **Description:** Reads user input from the terminal.
- **Functionality:** This function reads a line of input from the terminal using the `getline` function and returns the input as a string.

### 25. env_load
- **Description:** Loads the shell environment.
- **Functionality:** This function loads the shell environment from configuration files such as `.bashrc` or `.profile`. It sets up environment variables and other settings based on the contents of these files.

### 26. env_free
- **Description:** Frees the shell environment.
- **Functionality:** This function releases the memory allocated for the shell environment, including environment variables and other data structures.

### 27. _strcat
- **Description:** Concatenates two strings.
- **Functionality:** This function appends a copy of the null-terminated string `src` to the end of the null-terminated string `dest`, overwriting the null character at the end of `dest`, and then adds a terminating null character. The strings may not overlap, and the `dest` string must have enough space for the result.

### 28. _strcmp
- **Description:** Compares two strings.
- **Functionality:** This function compares the null-terminated strings `str1` and `str2`. It returns an integer less than, equal to, or greater than zero if `str1` is found, respectively, to be less than, to match, or be greater than `str2`.

### 29. _strncmp
- **Description:** Compares two strings up to a specified length.
- **Functionality:** This function compares at most the first `n` bytes of the null-terminated strings `str1` and `str2`. It returns an integer less than, equal to, or greater than zero if `str1` is found, respectively, to be less than, to match, or be greater than `str2`.

### 30. _strcpy
- **Description:** Copies a string.
- **Functionality:** This function copies the null-terminated string `src` to the memory pointed to by `dest`. It returns a pointer to `dest`.

### 31. _str_len
- **Description:** Calculates the length of a string.
- **Functionality:** This function calculates the length of the null-terminated string `str`, excluding the terminating null character.

### 32. _strdup
- **Description:** Duplicates a string.
- **Functionality:** This function duplicates the null-terminated string `str` using memory allocated with `malloc`. It returns a pointer to the duplicated string.

### 33. _strsep
- **Description:** Tokenizes a string.
- **Functionality:** This function searches the null-terminated string `str` for the first occurrence of any character in the null-terminated string `delim`. It replaces the delimiter character found in `str` with a null character and returns a pointer to the beginning of the token.

### 34. _strcspn
- **Description:** Calculates the length of the initial segment of str1 that consists of characters not in str2.
- **Functionality:** This function calculates the length of the initial segment of the null-terminated string `str1` that consists of characters not in the null-terminated string `str2`.

### 35. str_concat
- **Description:** Concatenates two strings.
- **Functionality:** This function appends a copy of the null-terminated string `src` to the end of the null-terminated string `dest`, overwriting the null character at the end of `dest`, and then adds a terminating null character. The strings may not overlap, and the `dest` string must have enough space for the result.

### 36. _getenv
- **Description:** Retrieves the value of an environment variable.
- **Functionality:** This function searches the shell environment for the specified environment variable `var_name` and returns a pointer to its value.

### 37. _isdigit
- **Description:** Checks if a character is a digit.
- **Functionality:** This function checks if the character `chr` is a digit (0 through 9) according to the ASCII character set. It returns a non-zero value if `chr` is a digit, otherwise returns 0.

### 38. _atoi
- **Description:** Converts a string to an integer.
- **Functionality:** This function parses the null-terminated string `input_string` as an integer and returns the result.

### 39. find_mate
- **Description:** Finds a command in the shell environment.
- **Functionality:** This function searches the shell environment for the specified command `comm` and returns a pointer to its location.

### 40. clear_debris
- **Description:** Removes redundant characters from a string.
- **Functionality:** This function removes any occurrences of the characters in the null-terminated string `c_string` from the null-terminated string `str`.

### 41. find_nest
- **Description:** Finds the shell environment.
- **Functionality:** This function returns a pointer to the shell environment.

### 42. turtles_nest
- **Description:** Creates a shell environment.
- **Functionality:** This function creates a new shell environment using memory allocated with `malloc` and returns a pointer to it.

### 43. turtle_eggs
- **Description:** Executes shell commands.
- **Functionality:** This function parses the null-terminated string `p_string` as shell commands and executes them. It returns the exit status of the last executed command.

### 44. free_strvec
- **Description:** Frees memory allocated to a string vector.
- **Functionality:** This function releases the memory allocated for the string vector `strvec`, including the strings it contains.

### 45. set_turtle_free_or_not
- **Description:** Sets the shell environment.
- **Functionality:** This function sets the shell environment to the specified value.

### 46. baby_turtles
- **Description:** Tokenizes a string.
- **Functionality:** This function breaks the null-terminated string `data` into tokens using the null-terminated string `delim` as the delimiter. It returns a pointer to the first token found.

### 47. make_turtlets
- **Description:** Creates a new shell environment.
- **Functionality:** This function creates a new shell environment with the specified name `name` and the specified command list `comm`. It returns a pointer to the newly created shell environment.

### 48. make_turtlet
- **Description:** Creates a new shell environment.
- **Functionality:** This function creates a new shell environment with the specified name `name` and the specified command list `comm`. It returns a pointer to the newly created shell environment.

### 49. no_such_turtle
- **Description:** Handles command not found errors.
- **Functionality:** This function prints an error message indicating that the specified command `comm` was not found in the shell environment.

### 50. left_uturn
- **Description:** Redirects the standard input from a file.
- **Functionality:** This function redirects the standard input (`stdin`) from the specified file.

