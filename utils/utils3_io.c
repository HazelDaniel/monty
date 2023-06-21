#include "../main.h"

void parse_file_lines(mont_com_t **comm_ptr, char *mont_path)
{
	int access_n, read_n, count = 0, i;
	ssize_t fd;
	char *buff = NULL, *fd_str = NULL;

	if (!mont_path)
		return;
	access_n = access(mont_path, F_OK);
	if (access_n != 0)
	{
		puts("directory does not exist!");
		return;
	}
	fd = open(mont_path, O_RDONLY);
	if (fd == -1)
	{
		printf("can't open directory :%s\n", mont_path);
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
				return;
		}
		count++;
	}
	if (read_n == -1)
		puts("error with the read");

	(void)parse_to_commands(comm_ptr, buff);
	// fd_str = _itoa(fd);
	// if (close(fd) != -1)
	// {
	// 	free(fd_str);
	// 	return;
	// }
	// write(STDERR_FILENO, "Error: Can't close fd ", 22);
	// write(STDERR_FILENO, fd_str, _strlen(fd_str));
	// write(STDERR_FILENO, "\n", 1);

	// free(fd_str);
}
