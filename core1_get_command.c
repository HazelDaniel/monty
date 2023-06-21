#include "main.h"

/**
 * get_command - a function that gets
 * the matching command for an opcode
 * @command: the raw command
 * @format: the pointer to the current mode
 * @lineno: the line number
 * Return: int (*x)(char **)
 **/
int (*get_command(char *command, int *format, int lineno))
	(char **args, int *format, int lineno)
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
		{0, handle_nop}, { "pop", handle_pop }, { 0, 0 }
	};
	int i;

	for (i = 0; funcs[i].f; i++)
	{
		if (is_start_str(funcs[i].name, command))
		{
			if (funcs[i].name)
				break;
		}
	}
	return (funcs[i].f);
}
