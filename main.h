#ifndef ___MAIN_
#define ___MAIN_

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include "deque.h"

/* USER-DEFINED MACROS */
#define DEQUE (mont_deque->deque)
#define COMMANDS (mont_deque->commands)
#define BUFF_LEN 1024
#define SENTINEL ("<monty_preserved>")
#define STACK_MODE (1)
#define QUEUE_MODE (-1)
#define DEQ_SIZE (50)
#define RAISE(x, y) raise_err(x, y)
#define _free_(x) (_free((void *)&(x)))

/* STRUCTS AND GLOBAL VARIABLES */
typedef struct command
{
	char *command;
	struct command *next;
} mont_com_t;

typedef struct
{
	char *name;
	int (* f)(char **args, int *format, int lineno);
} mont_opcode_t;

typedef struct
{
	deque_t *deque;
	mont_com_t *commands;
} mont_stack_t;
/* <<<<UNUSED>>>>> */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/* <<<<UNUSED>>>>> */

extern mont_stack_t *mont_deque;

/* STRING UTILS */
char *_strtok(char *str, char *delim);
char **_splitstr(char *str, char *delim);
unsigned int _strlen(char *str);
int in_str(char c, char *str);
char *_trim(char *str);
int first_oc_of(char *str, char c);
void srch_rpl_newline(char **main_str, char *r);
char *_strddup(char *src);
char *_strdcat(char *dest, char *src);
char *_strvcat(char *first_str, ...);
int is_end_str(char *strsub, char *strsup);
int last_oc_of(char *str, char c);
int is_start_str(char *strsub, char *strsup);
int is_digit(char c);
int last_spn_oc(int (*f)(char c), char *str);
int is_num_str(char *str);
int dig_len(int num);
char *_itoa(int num);
int is_word(char c);

/* MEM UTILS */
void *_realloc(void *ptr, size_t old_size, size_t size);
void _memcpy(void *ptr, const void *newptr, unsigned int size);
void _memset(void *ptr, int val, size_t len);

/* STATE UTILS */
void empty_state_buff(char *delim);
void free_str_arr(char **str_arr, int is_dyn);

/* IO */
void parse_file_lines(mont_com_t **comm_ptr, char *callpwd);

/* LIST UTILS */
void append_comm(mont_com_t **list, char *command);
void free_comms(mont_com_t **list);
void format_commands(mont_com_t **list);
void print_comms(mont_com_t *list);
int parse_to_commands(mont_com_t **comm_ptr, char *string);
int execute_commands(mont_com_t *list);

/* HANDLER UTILS AND OPCODE HANDLERS*/
int (*get_command(char *command, int *format, int lineno))(char **args, int *format, int lineno);

int handle_push(char **args, int *format, int lineno);
int handle_pint(char **args, int *format, int lineno);
int handle_pall(char **args, int *format, int lineno);
int handle_pop(char **args, int *format, int lineno);
int handle_swap(char **args, int *format, int lineno);
int handle_add(char **args, int *format, int lineno);
int handle_nop(char **args, int *format, int lineno);
int handle_sub(char **args, int *format, int lineno);
int handle_div(char **args, int *format, int lineno);
int handle_mul(char **args, int *format, int lineno);
int handle_mod(char **args, int *format, int lineno);
int handle_pchar(char **args, int *format, int lineno);
int handle_pstr(char **args, int *format, int lineno);
int handle_rotl(char **args, int *format, int lineno);
int handle_rotr(char **args, int *format, int lineno);
int handle_stack(char **args, int *format, int lineno);
int handle_queue(char **args, int *format, int lineno);
void raise_err(char *message, int status);

/* MISC */
void _free(void **ptr);
#endif/*___MAIN_*/
