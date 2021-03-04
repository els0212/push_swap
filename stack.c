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

void					free_stack(t_stack *root)
{
	t_stack	del;
	t_stack	curr;

	if (!root)
		return ;
	curr = *root;
	while (curr)
	{
		del = curr;
		curr = curr->next;
		free(del);
	}
	free(root);
}

int			get_size(t_stack *root)
{
	int		ret;
	t_stack	curr;

	ret = 0;
	if (!root)
		return (0);
	curr = *root;
	while (curr)
	{
		curr = curr->next;
		ret++;
	}
	return (ret);
}

t_stack		get_top(t_stack *root)
{
	t_stack	curr;

	if (!*root)
		return (0);
	curr = *root;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

int			push(t_stack *root, int n)
{
	t_stack	new;
	t_stack	curr;

	if (!(new = init_stack(n)))
		return (-1);
	if (!*root)
		*root = new;
	else
	{
		curr = get_top(root);
		//printf("in push, curr =%d\n", curr->content);
		curr->next = new;
	}
	return (0);
}

t_stack		pop(t_stack *root)
{
	t_stack	top;
	t_stack	prev;

	if (!(top = get_top(root)))
		return (0);
	prev = *root;
	if (prev == top)
		*root = 0;
	else
	{
		while (prev && prev != top && prev->next && prev->next != top)
			prev = prev->next;
		prev->next = 0;
	}
	return (top);
}

int		down_top(t_stack *root)
{
	t_stack	prev;
	t_stack	prev_2;
	t_stack	top;

	if (!root)
		return (0);
	else if (!(top = get_top(root)))
		return (0);
	prev = *root;
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

void	rotate_stack(t_stack *root, int reverse)
{
	t_stack	new_root;
	t_stack	prev_root;

	if (!*root)
		return ;
	prev_root = *root;
	if (reverse == 0)
	{
		new_root = pop(root);
		if (prev_root != new_root)
			new_root->next = prev_root;
	}
	else
	{
		new_root = prev_root->next;
		if (!new_root)
			new_root = prev_root;
		else
		{
			push(root, prev_root->content);
			free(prev_root);
		}
	}
	*root = new_root;
}
