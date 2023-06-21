#include "main.h"

int handle_queue(char **args, int *format, int lineno)
{
	*format = QUEUE_MODE;
	return (1);
}

int handle_pop(char **args, int *format, int lineno)
{
	char *error_message, *line_str;

	if (deque_empty(DEQUE))
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ": ", "can't pop an empty stack");
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	(void)dequeue_tail(DEQUE);
	return (1);
}
