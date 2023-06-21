#include "main.h"

mont_stack_t *mont_deque = NULL;

int main(int argc, char **argv)
{
	char *error_message;
	int status;

	if (argc != 2)
	{
		error_message = _strvcat("USAGE: monty file", NULL);
		RAISE(error_message, EXIT_FAILURE);
	}
	mont_deque = (mont_stack_t *)malloc(sizeof(mont_stack_t));
	if (!mont_deque)
	{
		error_message = _strddup("Error: malloc failed");
		RAISE(error_message, EXIT_FAILURE);
	}
	DEQUE = create_deque(DEQ_SIZE);
	if (!DEQUE)
	{
		error_message = _strddup("Error: malloc failed");
		RAISE(error_message, EXIT_FAILURE);
	}
	parse_file_lines(&COMMANDS, argv[1]);
	status = execute_commands(COMMANDS);

	free_comms(&COMMANDS);
	free_deque(&DEQUE);
	return (EXIT_SUCCESS);
}
