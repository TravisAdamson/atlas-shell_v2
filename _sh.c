#include "_sh.h"

extern char **environ;

/**
 * main - Main function for hsh
 * @argc: The arguments from the command line
 * @argv: The number of arguments given
 * Return: 0 for success, -1 for failure
*/

int main(int argc, char **argv)
{
	char **env = environ;
	char *prog = argv[0];
	if (argc == 0)
		printf("Stuff");
	if (prog)
		printf("No Stuff");
	if (env)
		printf("All the stuffs");
	return (0);
}
