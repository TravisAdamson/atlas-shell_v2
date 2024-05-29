#include "_sh.h"

static void detect_comms(char *data);

int shell_cracked(char *data)
{
	c_lst_t *temp = NULL;
	int parsed = 0;

	if (!data)
		return (-1);
	
	detect_comms(data);

}

/**
 * detect_comms - detect compatible command opperators
 * @input: input from command line
*/

static void detect_comms(char *data)
{
	int i = 0;

	for (; data[i]; i++)
	{
		if (data[i] == ';')
			comm_data.op_array[comm_data.op_add++] = 0x1, comm_data.op_ct++;
		else if (data[i] == '&' && data[i + 1] == '&')
			comm_data.op_array[comm_data.op_add++] = 0x2, comm_data.op_ct++, i++;
		else if (data[i] == '|' && data[i + 1] != '|')
			comm_data.op_array[comm_data.op_add++] = 0x3, comm_data.op_ct++;
		else if (data[i] == '|' && data[i + 1] == '|')
			comm_data.op_array[comm_data.op_add++] = 0x4, comm_data.op_ct++, i++;
		else if (data[i] == '>' && data[i + 1] != '>')
			comm_data.op_array[comm_data.op_add++] = 0x5, comm_data.op_ct++;
		else if (data[i] == '>' && data[i + 1] == '>')
			comm_data.op_array[comm_data.op_add++] = 0x6, comm_data.op_ct++, i++;
		else if (data[i] == '<' && data[i + 1] != '<')
			comm_data.op_array[comm_data.op_add++] = 0x7, comm_data.op_ct++;
		else if (data[i] == '<' && data[i + 1] == '<')
			comm_data.op_array[comm_data.op_add++] = 0x8, comm_data.op_ct++, i++;
	}
}