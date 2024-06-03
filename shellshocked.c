#include "shell.h"

p_data_t prog;
c_data_t comm_data;

/**
 * main - main function that prompts for input, parses it
 *
 * Return: 0 on success, -1 on error
 */

int main(int argc, char **argv)
{
	char *command_line = NULL;
	size_t command_line_len = 0;
	int prompt_check = 0;

	(void)argc;
	prog.prog_name = argv[0];

	while (1)
	{
		signal(SIGINT, handle_turtle_interrupt);
		/**
		 * * Get input from the user
		 */
		prompt_check = feed_the_turtle("Shellshocked: ", &command_line, &command_line_len);
		if (prompt_check == -1)
			free(command_line), exit(0);
		else if (prompt_check == 1)
			continue;
		if (empty_turtle_shell(command_line) == 0)
		{
			free(command_line), command_line = NULL;
			continue;
		}
		/**
		 * Parse the input into an array of commands.
		 */
		turtle_surgery(command_line);
		/**
		 * Print a turtle fact if the first token is "turtle".
		 */
		turtle_cross_road_or_not(comm_data.comms);
		/**
		 * Free the memory allocated for the command line and the command array.
		 */
		set_turtle_free_or_not();
		if (command_line != NULL)
			free(command_line), command_line = NULL;
		fflush(stdout);
	}
	return (0);
}
