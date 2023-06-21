#include "../main.h"

/**
 * raise_err - a function that prints
 * an error message to the standard output and exits
 * @message: the message to be printed
 * @status: the exit status of the error message
 * Return: void
 **/
void raise_err(char *message, int status)
{
	int len = _strlen(message);

	write(2, message, len);
	_free_(message);
	exit(status);
}
