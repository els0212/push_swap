#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack*	t_stack;
struct					s_stack
{
	int					content;
	t_stack				next;
};

t_stack					init_stack(int n);
void					free_stack(t_stack stack);
int						get_size(t_stack stack);
t_stack					get_top(t_stack stack);
int						push(t_stack stack, int n);
t_stack					pop(t_stack stack);
int						down_top(t_stack stack);
void					rotate_stack(t_stack stack, int reverse);
