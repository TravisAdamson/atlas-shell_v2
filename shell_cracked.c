#include "_sh.h"

static void detect_comms(char *data);
static int add_cmd(char *extract_string, c_lst_t **commands);
static int parse_opp(char *data);
static int parse_spc(c_lst_t *comm);

/**
 * shell_cracked - Parses data
 * @data: The data from command line
*/

int shell_cracked(char *data)
{
	c_lst_t *temp = NULL;
	int parsed = 0;

	if (!data)
		return (-1);
	
	detect_comms(data);
	parsed = parse_opp(data);

	if (!parsed)
		add_comm(data, &comm_data.comms);
	for (temp = comm_data.comms; temp; temp = temp->next)
		parse_spc(temp);
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

/**
 * parse_ops - .
 * @data: data entered to command line
 * Return: 1 if input parsed, 0 if not, -1 upon improper input
*/

static int parse_opp(char *data)
{
	char *extract_string = NULL, *data_cpy = NULL;

	if (!data)
		return (-1);
	for (
		data_cpy = data;
		(extract_string = sep(&data_cpy, OPS));
		comm_data.cmd_ct++
	)
		add_comm(extract_string, &comm_data.comms);
	if (extract_string)
		extract_string = NULL;
	if (data_cpy)
		free(data_cpy), data_cpy = NULL;
	return (comm_data.cmd_ct ? 1 : 0);
}

/**
 * add_comm - adds node to command segment list
 * @extract_str: split string from command line input containing command string
 * @commands: list of separated command segments
 * Return: 0 upon succes, -1 upon memory allocation failure
*/

static int add_comm(char *extract_string, c_lst_t **comms)
{
	c_lst_t *add = NULL, *tmp = NULL;

	if (!extract_string)
		return (-1);
	add = _calloc(sizeof(c_lst_t), 1);
	if (!add)
		return (-1);
	add->cmd_name = _strdup(extract_string);
	add->cmd_ind = comm_data.cmd_ct + 1;
	add->next = NULL;
	if (!*comms)
		add->prev = NULL,
		*comms = add;
	else
	{
		for (tmp = *comms; tmp; tmp = tmp->next)
			if (!tmp->next)
			{
				add->prev = tmp;
				tmp->next = add;
				break;
			}
	}
	return (0);
}

/**
 * parse_spc - parses/tokenizes input by whitespace into string vector
 * @cmd: command list
 * Return: 1 if input parsed to command, 0 if not, -1 upon improper input
 */

static int parse_spc(c_lst_t *comm)
{
	int i = 0;
	char *extract_string = NULL, *data_cpy = NULL;

	if (!comm)
		return (-1);
	for (
		data_cpy = comm->cmd_name;
		(extract_string = sep(&data_cpy, SPC_DELIM));
		i++
	)
		comm->comm[i] = _strdup(extract_string);
	if (extract_string)
		extract_string = NULL;
	if (data_cpy)
		free(data_cpy), data_cpy = NULL;
	return (i ? 1 : 0);
}