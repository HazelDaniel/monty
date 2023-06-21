#ifndef ___MAIN_
#define ___MAIN_

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>

/* USER-DEFINED MACROS */
#define BUFF_LEN 1024
#define SENTINEL ("<monty_preserved>")
#define STACK_MODE (1)
#define QUEUE_MODE (-1)

typedef struct command
{
	char *command;
	struct command *next;
} mont_com_t;

typedef struct
{
	char *name;
	int (* f)(char **args, int *format);
} mont_opcode_t;

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

/* HANDLER UTILS AND OPCODE HANDLERS*/
int (*get_command(char *command, int *format))(char **args, int *format);

int handle_push(char **args, int *format);
int handle_pint(char **args, int *format);
int handle_pall(char **args, int *format);
int handle_swap(char **args, int *format);
int handle_add(char **args, int *format);
int handle_nop(char **args, int *format);
int handle_sub(char **args, int *format);
int handle_div(char **args, int *format);
int handle_mul(char **args, int *format);
int handle_mod(char **args, int *format);
int handle_pchar(char **args, int *format);
int handle_pstr(char **args, int *format);
int handle_rotl(char **args, int *format);
int handle_rotr(char **args, int *format);
int handle_stack(char **args, int *format);
int handle_queue(char **args, int *format);
#endif/*___MAIN_*/
