#include "stack.h"

t_stack		init_stack(int n)
{
	t_stack	ret;

	if (!(ret = (t_stack)malloc(sizeof(t_stack))))
		return (0);
	ret->content = n;
	ret->next = 0;
	return (ret);
}

void					free_stack(t_stack stack)
{
	t_stack	curr;

	curr = stack;
	while (curr)
		free(curr);
}

int			get_size(t_stack stack)
{
	int		ret;
	t_stack	curr;

	ret = 0;
	curr = stack;
	while (curr)
	{
		curr = curr->next;
		ret++;
	}
	return (ret);
}

t_stack		get_top(t_stack stack)
{
	t_stack	curr;

	if (!stack)
		return (0);
	curr = stack;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

int			push(t_stack stack, int n)
{
	t_stack	new;
	t_stack	curr;

	if (!(new = init_stack(n)))
		return (-1);
	if (!(curr = get_top(stack)))
		stack = new;
	curr->next = new;
	return (0);
}

t_stack		pop(t_stack stack)
{
	t_stack	top;
	t_stack	prev;

	if (!(top = get_top(stack)))
		return (0);
	else if (!(prev = top))
		return (0);
	while (prev && prev != top)
		prev = prev->next;
	prev->next = 0;
	return (top);
}

int		down_top(t_stack stack)
{
	t_stack	prev;
	t_stack	prev_2;
	t_stack	top;

	if (!stack)
		return (0);
	else if (!(top = get_top(stack)))
		return (0);
	prev = stack;
	prev_2 = 0;
	while (prev && prev->next && prev->next != top)
	{
		prev_2 = prev;
		prev = prev->next;
	}
	if (!prev || prev == top || !prev_2)
		return (0);
	prev_2->next = top;
	top->next = prev;
	prev->next = 0;
	return (0);
}

void	rotate_stack(t_stack stack, int reverse)
{
	t_stack	new_root;
	t_stack	prev_root;

	prev_root = stack;
	if (!prev_root)
		return ;
	if (reverse == 0)
	{
		new_root = pop(stack);
		if (prev_root != new_root)
			new_root->next = prev_root;
	}
	else
	{
		new_root = stack->next;
		push(new_root, prev_root->content);
		free(prev_root);
	}
	stack = new_root;
}
