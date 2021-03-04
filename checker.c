#include "stack.h"
#include "libft/libft.h"
int	ft_chk_input(char *str)
{
	int	st;
	int	len;

	st = 0;
	if (!str)
		return (-1);
	len = ft_strlen(str);
	while (st < len)
	{
		if (ft_isdigit(str[st]) == 0)
			return (1);
		st++;
	}
	return (0);
}

void	error(t_stack *root)
{
	free_stack(root);
	write(1, "Error\n", 6);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_stack	*root;
	int		idx;
	int		num;

	root = (t_stack *)malloc(sizeof(t_stack));
	*root = 0;
	printf("argc = %d\n", argc);
	if (argc > 1)
	{
		idx = 1;
		while (idx < argc)
		{
			if (ft_chk_input(argv[idx]) != 0)
				error(root);
			num = ft_atoi(argv[idx]);
			push(root, num);
			printf("in main, now = %d\n", num);
			idx++;
		}
	}
	/*
	for(int i =0; i < 4; i++)
	{
		t_stack temp = pop(root);
		if (temp)
			printf("in man, pop = %d\n", temp->content);
		else
			printf("no temp\n");
	}
	rotate_stack(root, 1);
	t_stack curr = *root;
	while (curr)
	{
		printf("int main, after down_top, content : %d\n", curr->content);
		curr = curr->next;
	}
	*/
	free_stack(root);

	return (0);
}
