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


## The Shell Main Components

### check_turtle: This function checks whether a given file and/or directory exist. It returns -1 if the file doesn't exist, 0 if the directory doesn't exist, and 1 if both file and directory exist.
This function first checks if the provided file or directory exists by using the access system call. If the file or directory exists, it returns 1. If only the file exists, it returns 0. If neither the file nor the directory exists, it returns -1.

