#include "deque.h"

/**
 * create_deque - a function that creates
 * and initializes a deque
 * @size: the initial size provided
 * Return: deque_t *
 **/
deque_t *create_deque(unsigned int size)
{
	deque_t *new_deque = (deque_t *)malloc(sizeof(deque_t));

	if (!new_deque)
		return (0);

	new_deque->deque = malloc((size) * sizeof(int));
	new_deque->top = new_deque->tail = new_deque->head = 0;
	if (!new_deque->deque)
	{
		free(new_deque);
		return (0);
	}
	new_deque->size = size;

	return (new_deque);
}

/**
 * deque_full - a function that checks if a deque is full
 * @d: parameter of type deque_t *
 * Return: int
 **/
int deque_full(deque_t *d)
{
	if (!d)
		return (1);
	if ((d->tail % d->size) + 1 == (d->head % d->size))
		return (1);
	return (0);
}

/**
 * deque_empty - a function that checks if a deque is empty
 * @d: parameter of type deque_t *
 * Return: int
 **/
int deque_empty(deque_t *d)
{
	if (!d)
		return (1);
	if ((d->head % d->size) == (d->tail % d->size))
		return (1);
	return (0);
}

/**
 * relocate_deque - a function that re-allocates a deque
 * to an identical deque but with a larger size
 * @old_deque_ptr: parameter of type deque_t **
 * @size: the size difference
 * Return: deque_t *
 **/
deque_t *relocate_deque(deque_t **old_deque_ptr, unsigned int size)
{
	deque_t *new_deque = (deque_t *)malloc(sizeof(deque_t)),
	*old_deque = *old_deque_ptr;
	int i = 0, j = 0;

	if (!old_deque || !new_deque)
		return (NULL);

	if (!size || size < 0)
		return (old_deque);

	new_deque->deque = malloc((old_deque->size + size) * sizeof(int));
	new_deque->size = old_deque->size + size, new_deque->head = 0;

	if (!new_deque->deque)
	{
		free(new_deque);
		free_deque(old_deque_ptr);
		return (NULL);
	}
	for (j = 0, i = old_deque->head; i != old_deque->tail
	; i = (i + 1) % old_deque->size)
	{
		new_deque->deque[j++] = old_deque->deque[i];
	}
	new_deque->top = new_deque->tail = j;
	free_deque(old_deque_ptr);

	return (new_deque);
}

/**
 * free_deque - a function that frees up a deque
 * @d: parameter of type deque_t *
 * Return: void
 **/
void free_deque(deque_t **d)
{
	if (*d)
		free((*d)->deque);
	free(*d);
	*d = NULL;
}
