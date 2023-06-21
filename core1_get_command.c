#include "main.h"

/**
 * get_command - a function that gets
 * the matching command for an opcode
 * @command: the raw command
 * @format: the pointer to the current mode
 * Return: int (*x)(char **)
 **/
int (*get_command(char *command, int *format))(char **args, int *format)
{
	mont_opcode_t funcs[] = {
		{ "push", handle_push }, { "pint", handle_pint },
		{ "pall", handle_pall }, { "swap", handle_swap },
		{ "add", handle_add }, { "nop", handle_nop },
		{ "sub", handle_sub }, { "div", handle_div },
		{ "mul", handle_mul }, { "mod", handle_mod },
		{ "pchar", handle_pchar }, { "pstr", handle_pstr },
		{ "rotl", handle_rotl }, { "rotr", handle_rotr },
		{ "stack", handle_stack }, { "queue", handle_queue },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; funcs[i].name; i++)
	{
		if (is_start_str(funcs[i].name, command))
			break;
	}
	return (funcs[i].f);
}
