#include "shell.h"

/**
 * set_turtle_free_or_not - frees memory related to command array
 *
 * Return: void
 */
void set_turtle_free_or_not(void)
{
	c_lst_t *hold = NULL;
	int i = 0;

	if (comm_data.comms)
	{
		for (; comm_data.comms; comm_data.comms = hold)
		{
			hold = comm_data.comms->next;
			for (i = 0; comm_data.comms->comm[i]; i++)
				if (comm_data.comms->comm[i])
					free(comm_data.comms->comm[i]),
					comm_data.comms->comm[i] = NULL;
			if (comm_data.comms->cmd_name)
				free(comm_data.comms->cmd_name), comm_data.comms->cmd_name = NULL;
			if (comm_data.comms)
				free(comm_data.comms), comm_data.comms = NULL;
		}
	}
	if (comm_data.input)
		free(comm_data.input), comm_data.input = NULL;
}

/**
 * free_strvec - frees memory related to string vector
 * @strvec: string vector
 */

void free_strvec(char **strvec)
{
	int i = 0;

	for (; strvec[i]; i++)
		strvec[i] = NULL;
	if (*strvec)
		free(*strvec), *strvec = NULL;
}