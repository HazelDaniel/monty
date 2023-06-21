#include "monty.h"

/**
  * handle_queue - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_queue(char **args, int *format, int lineno)
{
	(void)args, (void)format, (void)lineno;
	*format = QUEUE_MODE;
	return (1);
}

/**
  * handle_pop - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_pop(char **args, int *format, int lineno)
{
	char *error_message, *line_str;

	(void)args, (void)format, (void)lineno;
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
