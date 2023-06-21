#include "../main.h"

void parse_file_lines(mont_com_t **comm_ptr, char *mont_path)
{
	int access_n, read_n, count = 0, i;
	ssize_t fd;
	char *buff = NULL, *fd_str = NULL, *error_message;

	if (!mont_path)
		return;
	access_n = access(mont_path, F_OK);
	if (access_n != 0)
	{
		error_message = _strvcat("Can't open file ", mont_path, NULL);
		RAISE(error_message, EXIT_FAILURE);
		return;
	}
	fd = open(mont_path, O_RDONLY);
	if (fd == -1)
	{
		error_message = _strvcat("Can't open file ", mont_path, NULL);
		RAISE(error_message, EXIT_FAILURE);
		return;
	}
	buff = malloc(BUFF_LEN * sizeof(char));
	if (!buff)
		return;
	_memset(buff, 0, BUFF_LEN);
	while ((read_n = read(fd, buff, BUFF_LEN)) > 0)
	{
		if (count >= (int)_strlen(buff) - 1)
		{
			buff = _realloc(buff, _strlen(buff) + 1, _strlen(buff) + 121);
			if (!buff)
			{
				error_message = _strddup("Error: malloc failed");
				RAISE(error_message, EXIT_FAILURE);
			}
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
		error_message = _strvcat("couldn't close file: ", mont_path, "exiting gracefully", NULL);
		RAISE(error_message, EXIT_FAILURE);
		return;
	}
}
