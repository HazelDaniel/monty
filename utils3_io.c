#include "../main.h"

/**
 * access_or_raise - a function that tries
 * to access a file and raises an error on failure
 * @mont_path: the path to the monty bytecode
 * @msg: the error message
 * Return: void
 **/
static void access_or_raise(char *mont_path, char *msg)
{
	int access_n;
	char *error_message;

	access_n = access(mont_path, F_OK);
	if (access_n != 0)
	{
		error_message = _strvcat(msg, mont_path, NULL);
		RAISE(error_message, EXIT_FAILURE);
	}
}

/**
 * open_or_raise - a function that tries
 * to open a file and raises an error on failure
 * @mont_path: the path to the monty bytecode
 * @msg: the error message
 * Return: void
 **/
static void open_or_raise(char *mont_path, char *msg)
{
	int fd;
	char *error_message;

	fd = open(mont_path, O_RDONLY);
	if (fd == -1)
	{
		error_message = _strvcat(msg, mont_path, NULL);
		RAISE(error_message, EXIT_FAILURE);
	}
}

/**
 * alloc_str_or_raise - a function that checks if a
 * string is successfully allocated and raises an error on failure
 * @buff: the string that was allocated
 * Return: void
 **/
static void alloc_str_or_raise(char *buff)
{
	char *error_message;

	if (!buff)
	{
		error_message = _strddup("Error: malloc failed");
		RAISE(error_message, EXIT_FAILURE);
	}
}

/**
 * parse_file_lines - a function that parses
 * a monty bytecode file to commands
 * @comm_ptr: the address of the monty command list
 * @mont_path: the file name of the monty byte code
 * Return: void
 **/
void parse_file_lines(mont_com_t **comm_ptr, char *mont_path)
{
	int access_n, read_n, count = 0, i;
	ssize_t fd;
	char *buff = NULL, *fd_str = NULL, *error_message;

	if (!mont_path)
		return;
	access_or_raise(mont_path, "Can't open file ");
	fd = open(mont_path, O_RDONLY);
	if (fd == -1)
	{
		error_message = _strvcat("Can't open file ", mont_path, NULL);
		RAISE(error_message, EXIT_FAILURE);
	}
	buff = malloc(BUFF_LEN * sizeof(char));
	alloc_str_or_raise(buff);
	_memset(buff, 0, BUFF_LEN);
	while ((read_n = read(fd, buff, BUFF_LEN)) > 0)
	{
		if (count >= (int)_strlen(buff) - 1)
		{
			buff = _realloc(buff, _strlen(buff) + 1, _strlen(buff) + 121);
			alloc_str_or_raise(buff);
		}
		count++;
	}
	if (read_n == -1)
	{
		error_message = _strvcat("couldn't read. exiting gracefully", NULL);
		RAISE(error_message, EXIT_FAILURE);
	}
	(void)parse_to_commands(comm_ptr, buff);
	if (close(fd) == -1)
	{
		error_message = _strvcat("couldn't close file: "
		, mont_path, "exiting gracefully", NULL), RAISE(error_message, EXIT_FAILURE);
	}
}
