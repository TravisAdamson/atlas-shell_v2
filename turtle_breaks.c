#include "_sh.h"

/**
 * turtle_breaks - handles SIGINT
 * @sig: signal
 *
 */
void turtle_breaks(int sig)
{
	/*SIGINT is a signal that is sent to a deal with for Ctrl+C. */
	if (sig == SIGINT)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n# ", 3);
	}
}
