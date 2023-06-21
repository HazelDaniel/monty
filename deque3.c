#include "main.h"

/**
 * deque_len - a function that computes the
 * active length of a deque
 * @d: parameter of type deque_t *
 * Return: int
 **/
int deque_len(deque_t *d)
{
	int x, i, count = 0;

	if (deque_empty(d))
		return (count);
	x = d->tail;
	x = (((x - 1) % d->size) + d->size) % d->size;
	for (i = x; i != d->head; i = (((i - 1) % d->size) + d->size) % d->size)
		count++;
	count++;

	return (count);
}
