#include "../main.h"

/**
 * _memcpy - copies the content of a pointer
 * into another
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 * Return: void
 */
void _memcpy(void *ptr, const void *newptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
	char_newptr[i] = 0;
}

/**
 * _realloc - a function that reallocates a memory block
 * @ptr: the address of the old memory block
 * @old_size: the number of elements in the old memory block
 * @size: the number of elements in the new memory block
 * Return: void *
 **/
void *_realloc(void *ptr, size_t old_size, size_t size)
{
	char *res_tmp = NULL, *ptr_cp;
	void *res = NULL;
	int index = 0;

	if (size == 0 && ptr)
	{
		_free_(ptr), ptr = NULL;
		return (NULL);
	}
	if (ptr == NULL)
	{
		res = malloc(size);
		res_tmp = res;
		res_tmp[size - 1] = '\0';
	}
	else
	{
		if (size == old_size)
			return (ptr);

		ptr_cp = ptr;
		res = malloc(size);
		if (res == NULL)
		{
			_free_(ptr), ptr = NULL;
			return (res);
		}
		res_tmp = res;
		for (index = 0; index < (int)size; index++)
		{
			if (size > old_size && index == (int)old_size)
				break;
			res_tmp[index] = *ptr_cp++;
		}
		--index, res_tmp[index] = '\0';
		_free_(ptr), ptr = NULL;
	}

	return (res);
}
