#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack*	t_stack;
struct					s_stack
{
	int					content;
	t_stack				next;
};

t_stack					init_stack(int n);
void					free_stack(t_stack *root);
int						get_size(t_stack *root);
t_stack					get_top(t_stack *root);
int						push(t_stack *root, int n);
t_stack					pop(t_stack *root);
int						down_top(t_stack *root);
void					rotate_stack(t_stack *root, int reverse);
