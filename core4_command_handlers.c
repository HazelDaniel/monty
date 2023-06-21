#include "main.h"

int handle_pchar(char **args, int *format, int lineno)
{
	char *error_message, *line_str;
	int ascii_char;
	int i;

	if (deque_empty(deque))
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":", "can't pchar, stack empty", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}
	i = deque->tail;
	i = (((i - 1) % deque->size) + deque->size) % deque->size;
	ascii_char = deque->deque[i];
	if (ascii_char > 127 || ascii_char < 0)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":", "can't pchar, value out of range", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	printf("%c\n", ascii_char);
	return (1);
}

int handle_pstr(char **args, int *format, int lineno)
{
	char *error_message, *line_str;
	int ascii_char, d_len = deque_len(deque), i, x,
	index = 0;
	char *result;

	if (deque_empty(deque))
		print_deque(deque);

	result = malloc((d_len + 1) * sizeof(char));
	_memset(result, 0, d_len + 1);
	if (!result)
	{
		error_message = _strddup("Error: malloc failed");
		RAISE(error_message, EXIT_FAILURE);
	}
	x = deque->tail;
	x = (((x - 1) % deque->size) + deque->size) % deque->size;
	for (i = x; i != deque->head; i = (((i - 1) % deque->size) + deque->size) % deque->size)
	{
		if (deque->deque[i] <= 0 || deque->deque[i] > 127)
			break;
		result[index++] = deque->deque[i];
	}
	if (deque->deque[i] > 0 && deque->deque[i] <= 127)
		result[index] = deque->deque[i];
	printf("%s\n", result);
	_free_(result);

	return (1);
}

int handle_rotl(char **args, int *format, int lineno)
{
	int top;

	if (deque_empty(deque))
		return (1);

	top = dequeue_tail(deque);
	enqueue_head(&deque, top);

	return (1);
}

int handle_rotr(char **args, int *format, int lineno)
{
	int bottom;

	if (deque_empty(deque))
		return (1);

	bottom = dequeue_head(deque);
	enqueue_tail(&deque, bottom);

	return (1);
}

int handle_stack(char **args, int *format, int lineno)
{
	*format = STACK_MODE;
	return (1);
}
