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

void	error(t_stack root)
{
	free_stack(root);
	write(1, "Error\n", 6);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_stack	root;
	int		idx;
	int		num;

	root = init_stack(0);
	if (argc > 1)
	{
		idx = 1;
		while (idx < argc)
		{
			if (ft_chk_input(argv[idx]) != 0)
				error(root);
			num = ft_atoi(argv[idx]);
			push(root, num);
			idx++;
		}
	}
	t_stack curr = root;
	while (curr)
	{
		printf("content : %d\n", curr->content);
		curr = curr->next;
	}
	free_stack(root);
	return (0);
}
