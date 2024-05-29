#include "_sh.h"

/**
 * empty_data - verifies if data is only space characters
 * @data: input string
 * Return: 0 if length of string equal to number of whitespaces, -1 otherwise
 */

int empty_data(char *data)
{
	int i = 0, spaces = 0;

	if (data)
		for (; data[i]; i++)
			if (
				data[i] == ' ' ||
				data[i] == '\t' ||
				data[i] == '\n' ||
				data[i] == '\r'
			)
				spaces++;
	return (spaces == _strlen(data) ? 1 : 0);
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

/**
 * free_comm_data - frees memory related to command vector created in main
 */

void free_comm_data(void)
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