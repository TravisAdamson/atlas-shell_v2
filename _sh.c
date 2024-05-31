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
    int exit_status = 0; /* Initialize exit status variable */

    (void)argc;
    prog.prog_name = argv[0];

    while (1)
    {
        comm_data.op_ind = 0, comm_data.op_add = 0, comm_data.op_ct = 0;
        comm_data.cmd_ind = 0, comm_data.cmd_ct = 0;
        signal(SIGINT, handle_interrupt);
        signal(SIGTSTP, handle_interrupt);
        prompt_value = prompt("Shellshocked:# ", &comm_data.input, &input_length);
        if (prompt_value < 0)
            continue;
        shell_cracked(comm_data.input);
        run_comm(comm_data.comms);
        /* Check if any command failed */
        exit_status = check_exit_status(comm_data.comms);
        free_comm_data();
        fflush(stdout);
    }

    return exit_status; /* Return the exit status */
}

/**
 * check_exit_status - Checks the exit status of commands
 * @comms: The linked list of commands
 * 
 * This function iterates through the linked list of commands and
 * checks the exit status of each command. If any command has a non-zero
 * exit status, it returns that status. If all commands have a zero exit
 * status, it returns zero.
 * 
 * Return: The exit status of commands
 */
int check_exit_status(c_lst_t *comms)
{
    while (comms)
    {
        if (comms->exit_status != 0)
            return comms->exit_status;
        comms = comms->next;
    }
    return 0; /* No command failed, return success */
}
