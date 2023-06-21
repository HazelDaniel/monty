#include "main.h"

/**
 * print_deque - a function that prints the contents of a
 * deque
 * @d: parameter of type deque_t *
 * Return: void
 **/
void print_deque(deque_t *d)
{
	int i, x;

	if (deque_empty(d))
		return;
	x = d->tail;
	x = (((x - 1) % d->size) + d->size) % d->size;
	for (i = x; i != d->head; i = (((i - 1) % d->size) + d->size) % d->size)
	{
		printf("%d\n", d->deque[i]);
	}
	printf("%d\n", d->deque[d->head]);
}

/**
 * dequeue_head - a function that dequeues
 * a deque from the head position
 * @d: parameter of type deque_t *
 * Return: int
 **/
int dequeue_head(deque_t *d)
{
	int x;

	if (deque_empty(d))
	{
		puts("deque underflow");
		exit(EXIT_FAILURE);
	}
	x = d->deque[d->head % d->size];
	d->head = (d->head + 1) % d->size;

	return (x);
}

/**
 * enqueue_head - a function that enqueues
 * a deque from the head position
 * @d: parameter of type deque_t *
 * @x: the value to be enqueued
 * Return: void
 **/
void enqueue_head(deque_t **d, int x)
{
	deque_t *dq = *d;

	if (deque_full(dq))
		dq = *d = relocate_deque(d, 100);

	if (!dq)
	{
		puts("malloc failed");
		exit(99);
	}

	if (deque_empty(dq))
	{
		dq->deque[dq->head] = x, dq->tail = (dq->tail + 1) % dq->size;
	}
	else
	{
		dq->head = (((dq->head - 1) % dq->size) + dq->size) % dq->size;
		dq->deque[dq->head] = x;
	}
}

/**
 * dequeue_tail - a function that dequeues
 * a deque from the tail position
 * @d: parameter of type deque_t *
 * Return: int
 **/
int dequeue_tail(deque_t *d)
{

	if (deque_empty(d))
	{
		puts("deque underflow");
		exit(EXIT_FAILURE);
	}
	d->tail--;
	d->tail = (((d->tail % d->size) + d->size) % d->size);

	return (d->deque[d->tail]);
}


/**
 * enqueue_tail - a function that enqueues
 * a deque from the tail position
 * @d: parameter of type deque_t *
 * @x: the value to be enqueued
 * Return: void
 **/
void enqueue_tail(deque_t **d, int x)
{
	deque_t *dq = *d;
	int i;

	if (deque_full(dq))
		dq = *d = relocate_deque(d, 100);

	if (!dq)
	{
		puts("malloc failed");
		exit(99);
	}

	i = dq->tail;
	dq->tail = (dq->tail + 1) % dq->size;
	dq->deque[i] = x;
}
