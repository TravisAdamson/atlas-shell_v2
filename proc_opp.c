#include "_sh.h"

/**
 * run_opp - runs when operators present
 * @comm: head of linked list of commands
 * Return: 0 upon success
*/

int run_opp(c_lst_t *comm)
{
	c_lst_t *temp = NULL;
	int l = 0x0, p = 0;

	for (temp = comm; temp; temp = temp->next, comm_data.op_ind++, comm_data.cmd_ind++)
		if (temp->comm[0])
		{
			if (comm_data.op_array[comm_data.op_ind] == 0x1)
				colon_opp(temp), l = 0x1;
			else if (comm_data.op_array[comm_data.op_ind] == 0x2)
			{
				if (!colon_opp(temp))
					break;
			}
			else if (comm_data.op_array[comm_data.op_ind] == 0x3)
			{
				p = p_count(&comm_data.op_array[comm_data.op_ind]);
				pipes(temp, p), l = 0x3;
			}
			else if (comm_data.op_array[comm_data.op_ind] == 0x4)
			{
				if (colon_opp(temp))
					break;
			}
			else if (comm_data.op_array[comm_data.op_ind] == 0x5)
				right_redirect(temp), l = 0x5;
			else if (comm_data.op_array[comm_data.op_ind] == 0x6)
				right_redirect_2(temp), l = 0x6;
			else if (comm_data.op_array[comm_data.op_ind] == 0x7)
				left_redirect(temp), l = 0x7;
			else if (comm_data.op_array[comm_data.op_ind] == 0x8)
				left_redirect_2(temp), l = 0x8;
			else if (temp->cmd_ind == comm_data.cmd_ct && l <= 0x4 && l != 0x3)
				colon_opp(temp);
		}
	return (0);
}

/**
 * colon_opp - colon command operator
 * @comms: selected command segment input
 * Return: 1 on success, otherwise returns 0
*/

int colon_opp(c_lst_t *comm)
{
	int l_error = 0;

	if (!comm)
		return (0);
	l_error = run_comm_branch(comm);
	if (l_error == 2 || l_error == 13 || l_error == 127)
	{
		run_error(comm->comm, l_error);
		return (0);
	}
	return (1);
}

/**
 * pipe - pipeline opps
 * @comm: selected command segment input
 * @p_count: number of pipes to be processed
 * Return: number of pipes processed, -1 otherwise
*/

int pipes(c_lst_t *comm, int p_count)
{
	c_lst_t *temp = NULL;
	int l_error = 0, p_comp = 0;

	if (!comm || !comm->next->comm[0] || !p_count)
		return (-1);
	pipe(comm_data.pipe_fd);
	for (
			temp = comm;
			temp;
			temp = temp->next, p_comp++
	)
	{
		run_comm_branch(temp);
		if (l_error)
			run_error(temp->comm, l_error);
	}
	colon_opp(temp);
	return (p_comp);
}

/**
 * p_count - counts pipes in commmand line input
 * @ops: array of operators pulled from input
 * Return: number of pipes
*/

int p_count(int *ops)
{
	int p = 0, i = 0;

	if (!ops)
		return (-1);
	for (; ops[i] == 0x3; p++, i++)
		;
	return (p);
}