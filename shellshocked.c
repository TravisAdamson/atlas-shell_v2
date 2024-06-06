#include "shell.h"

p_data_t prog;
c_data_t comm_data;
int last_exit;

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
		comm_data.op_ind = 0, comm_data.op_add = 0, comm_data.op_ct = 0;
		comm_data.cmd_ind = 0, comm_data.cmd_ct = 0;
		
		signal(SIGINT, handle_turtle_interrupt);
		signal(SIGTSTP, handle_turtle_interrupt);
		/**
		 * * Get input from the user
		 */
		prompt_check = feed_the_turtle("Shellshocked: ", &comm_data.input, &command_line_len);
		if (prompt_check < 0)
			continue;
		/**
		 * Parse the input into an array of commands.
		 */
		turtle_surgery(comm_data.input);
		/**
		 * Print a turtle fact if the first token is "turtle".
		 */
		turtle_cross_road_or_not(comm_data.comms);
		/**
		 * Free the memory allocated for the command line and the command array.
		 */
		set_turtle_free_or_not();

		fflush(stdout);
	}

	if (command_line)
		free(command_line), command_line = NULL;
	return (0);
}
