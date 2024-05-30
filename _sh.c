#include "_sh.h"

p_dt_t prog;
c_dt_t comm_data;

/**
 * main - Main function for hsh
 * @argc: The arguments from the command line
 * @argv: The number of arguments given
 * Return: 0 for success, -1 for failure
*/

int main(int argc, char **argv)
{
	size_t input_length = 0;
	int prompt_value = 0;

	(void)argc;
	prog.prog_name = argv[0];
	
	while (1)
	{
		comm_data.op_ind = 0, comm_data.op_add = 0, comm_data.op_ct = 0;
		comm_data.cmd_ind = 0, comm_data.cmd_ct = 0;
		signal(SIGINT, turtle_breaks);
		signal(SIGTSTP, turtle_breaks);
		prompt_value = prompt("Shellshocked:# ", &comm_data.input, &input_length);
		if (prompt_value < 0)
			continue;
		shell_cracked(comm_data.input);
		run_comm(comm_data.comms);
		shelled_turtle();
		fflush(stdout);
	}
	
	return (0);
}
