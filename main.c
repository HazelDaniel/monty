#include "main.h"

deque_t *deque = NULL;

int main(int argc, char **argv)
{
	char *test_char;
	mont_com_t *commands = NULL;
	int status;

	// test_char = _strddup("\n\n\n\n");
	// srch_rpl_newline(&test_char, "wee\n");
	// printf("resulting string is :%s\n", test_char);
	// free(test_char);
	if (argc != 2)
	{
		puts("wrong argument count!");
		exit(99);
	}
	deque = create_deque(DEQ_SIZE);
	if (!deque)
	{
		puts("malloc failed");
		exit(99);
	}
	parse_file_lines(&commands, argv[1]);
	status = execute_commands(commands);

	free_comms(&commands);
	free_deque(&deque);
	return (0);
}
