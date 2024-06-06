#include "shell.h"

/**
 * turtle_homing - runs when operators present
 * @comm: head of linked list of commands
 * Return: 0 upon success
*/

int turtle_homing(c_lst_t *comm)
{
	c_lst_t *temp = NULL;
	int l = 0x0, p = 0;

	for (temp = comm; temp; temp = temp->next, comm_data.op_ind++, comm_data.cmd_ind++)
		if (temp->comm[0])
		{
			if (comm_data.op_array[comm_data.op_ind] == 0x1)
				turtle_nap(temp), l = 0x1;
			else if (comm_data.op_array[comm_data.op_ind] == 0x2)
			{
				if (!turtle_nap(temp))
					break;
			}
			else if (comm_data.op_array[comm_data.op_ind] == 0x3)
			{
				p = current_length(&comm_data.op_array[comm_data.op_ind]);
				turtle_current(temp, p), l = 0x3;
				return (0);
			}
			else if (comm_data.op_array[comm_data.op_ind] == 0x4)
			{
				if (turtle_nap(temp))
					break;
			}
			else if (comm_data.op_array[comm_data.op_ind] == 0x5)
				turn_right(temp), l = 0x5;
			else if (comm_data.op_array[comm_data.op_ind] == 0x6)
				right_uturn(temp), l = 0x6;
			else if (comm_data.op_array[comm_data.op_ind] == 0x7)
				turn_left(temp), l = 0x7;
			else if (comm_data.op_array[comm_data.op_ind] == 0x8)
				left_uturn(temp), l = 0x8;
			else if (temp->cmd_ind == comm_data.cmd_ct && l <= 0x4 && l != 0x3)
				turtle_nap(temp);
		}
	return (0);
}

/**
 * turtle_nap - colon command operator
 * @comms: selected command segment input
 * Return: 1 on success, otherwise returns 0
*/

int turtle_nap(c_lst_t *comm)
{
	int l_error = 0;

	if (!comm)
		return (0);
	l_error = turtle_does(comm);
	if (l_error == 13 || l_error == 127)
	{
		no_such_turtle(comm->comm, l_error);
		return (0);
	}
	else if (l_error == 2)
	{
		no_such_turtle(comm->comm, 0);
		return (0);
	}
	return (1);
}

/**
 * turtle_current - pipeline opps
 * @comm: selected command segment input
 * @p_counted: number of pipes to be processed
 * Return: number of pipes processed, -1 otherwise
*/

int turtle_current(c_lst_t *comm, int p_counted)
{
	c_lst_t *temp = NULL;
	int l_error = 0, p_comp = 0;

	if (!comm || !comm->next->comm[0] || !p_counted)
		return (-1);
	if (p_counted == 2)
	{
		pipe(comm_data.pipe_fd);
		pipe(comm_data.pipe2_fd);
		l_error = turtle_does_too(comm);
		
		if (l_error)
			no_such_turtle(comm->comm, l_error);

		return (p_comp);
	}
	else
	{
		pipe(comm_data.pipe_fd);
		for (
			temp = comm;
			temp;
			temp = temp->next, p_comp++
		)
		{
			l_error = turtle_does(temp);
			if (l_error)
				no_such_turtle(temp->comm, l_error);
		}

		turtle_nap(temp);
		return (p_comp);
	}

	return (0);
}

/**
 * current_length - counts pipes in commmand line input
 * @ops: array of operators pulled from input
 * Return: number of pipes
*/

int current_length(int *ops)
{
	int p = 0, i = 0;

	if (!ops)
		return (-1);
	for (; ops[i] == 0x3; p++, i++)
		;
	return (p);
}