#include "_sh.h"

extern char **environ;
extern p_dt_t prog;
extern c_dt_t comm_data;

/**
 * main - Main function for hsh
 * @argc: The arguments from the command line
 * @argv: The number of arguments given
 * Return: 0 for success, -1 for failure
*/

int main(int argc, char **argv)
{
	char **env = environ;
	size_t input_length = 0;
	int prompt_value = 0;

	prog.prog_name = argv[0];
	
	while (1)
	{
		comm_data.op_ind = 0, comm_data.op_add = 0, comm_data.op_ct = 0;
		comm_data.cmd_ind = 0, comm_data.cmd_ct = 0;
		signal(SIGINT, handle_interrupt);
		prompt_value = prompt("Shellshocked:# ", &comm_data.input, &input_length);
		if (prompt_value < 0)
			continue;
		shell_cracked(comm_data.input);
	}

	if (argc == 0)
		printf("Stuff");
	if (prog.prog_name)
		printf("No Stuff");
	if (env)
		printf("All the stuffs");
	return (0);
}
