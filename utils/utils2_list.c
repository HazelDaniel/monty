#include "../main.h"

void append_com(mont_com_t **list, char *command)
{
	mont_com_t *new_comm = (mont_com_t *)malloc(sizeof(mont_com_t)), *current;
	static int id;

	if (!new_comm)
		return;
	new_comm->command = _strddup((char *)command);
	new_comm->next = NULL;

	if (!*list)
	{
		*list = new_comm;
	}
	else
	{
		current = *list;

		while (current && current->next)
			current = current->next;
		current->next = new_comm;
	}
}

/**
  * free_comms - a function that clears
	* all commands
	* @list: a parameter of type mont_com_t
  * Return: void .
 */
void free_comms(mont_com_t **list)
{
	mont_com_t *current = *list, *next = NULL;

	if (!current)
		return;
	while (current)
	{
		if (current->next == NULL)
		{
			_free_(current->command);
			_free_(current);
			*list = NULL;
			return;
		}
		next = current->next;
		_free_(current->command);
		_free_(current);
		current = next;
	}
}

void format_commands(mont_com_t **list)
{
	mont_com_t *current = *list;
	char *tmp;
	int last_sent_oc, first_hash_oc;

	if (!current)
		return;

	while (current)
	{
		first_hash_oc = first_oc_of(current->command, '#');
		if (first_hash_oc != -1)
			current->command[first_hash_oc] = '\0';
		if (is_end_str(SENTINEL, current->command))
		{
			tmp = _trim(current->command);
			if (tmp)
			{
				_free_(current->command);
				current->command = tmp;
			}
			last_sent_oc = last_oc_of(current->command, SENTINEL[0]);
			current->command[last_sent_oc] = '\0';
			if (current->command && _strlen(current->command) == 0)
				_free_(current->command);
		}

		current = current->next;
	}
}

/**
  * print_comms - a function that prints
	* all commands in a command flow
  * @list: parameter of type mont_com_t.
  * Return: void .
 */
void print_comms(mont_com_t *list)
{
	mont_com_t *current = list;

	while (current)
	{
		printf("Command: %s\n", current->command);
		current = current->next;
	}
}


/**
  * parse_to_commands - a function that parses
	* an input string into an array of command structs
  * @string: parameter of type char *.
	* @comm_ptr: the address of the monty command list
  * Return: int .
 */
int parse_to_commands(mont_com_t **comm_ptr, char *string)
{
	char **parse_list = NULL;
	int i;

	srch_rpl_newline(&string, "<monty_preserved>\n");
	parse_list = _splitstr(string, "\n");

	for (i = 0; parse_list[i]; i++)
		append_com(comm_ptr, parse_list[i]);
	if (*comm_ptr)
		format_commands(comm_ptr);

	free_str_arr(parse_list, 1);
	_free_(string);
	return (0);
}

int execute_commands(mont_com_t *list)
{
	mont_com_t *current = list;
	int format = STACK_MODE, lineno, (*f)(char **, int *, int),
	status, i;
	char *error_message, *line_str, *opcode;

	while (current)
	{
		lineno++;
		f = get_command(current->command, &format, lineno);
		if (f)
		{
			status = f(&current->command, &format, lineno);
			if (!status)
				return (0);
		}
		else
		{
			break;
			line_str = _itoa(lineno);
			opcode = _strddup(current->command);
			i = last_spn_oc(is_word, opcode);
			if (i != -1)
				opcode[i + 1] = '\0';

			error_message = _strvcat("L", line_str, ":", "unknown instruction ", opcode, NULL);
			_free_(line_str), _free_(opcode);
			RAISE(error_message, EXIT_FAILURE);
		}
		current = current->next;
	}
	return (1);
}
