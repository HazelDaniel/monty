#include "../main.h"

/**
 * execute_commands - a function that executes
 * the command strings in a monty list
 * @list: the monty list
 * Return: int
 **/
int execute_commands(mont_com_t *list)
{
	mont_com_t *current = list;
	int format = STACK_MODE, lineno = 1, (*f)(char **, int *, int),
	status, i;
	char *error_message, *line_str, *opcode;

	while (current)
	{
		f = get_command(current->command, &format, lineno);
		if (!current->command)
		{
			current = current->next, lineno++;
			continue;
		}
		if (f)
		{
			status = f(&current->command, &format, lineno);
			if (!status)
				return (0);
		}
		else
		{
			line_str = _itoa(lineno);
			opcode = _strddup(current->command);
			i = last_spn_oc(is_word, current->command);
			if (i != -1)
				opcode[i + 1] = '\0';

			error_message = _strvcat("L", line_str, ":"
			, "unknown instruction ", opcode, NULL);
			_free_(line_str), _free_(opcode);
			RAISE(error_message, EXIT_FAILURE);
		}
		current = current->next;
		lineno++;
	}
	return (1);
}
