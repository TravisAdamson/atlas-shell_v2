#include "shell.h"

/**
 * handle_turtle_interrupt - handles SIGINT
 * @sig: signal
 *
 */
void handle_turtle_interrupt(int sig)
{
	/*SIGINT is a signal that is sent to a deal with for Ctrl+C. */
	if (sig == SIGINT)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n# ", 3);
	}
}
