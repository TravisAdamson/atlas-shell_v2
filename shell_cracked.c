#include "_sh.h"

static void detect_comms(char *data);

/**
 * shell_cracked - Parses data
 * @data: The data from command line
*/

int shell_cracked(char *data)
{

	if (!data)
		return (-1);
	
	detect_comms(data);
	return (0);

}

/**
 * detect_comms - detect compatible command opperators
 * @data: input from command line
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