#include "checker.h"
#include <stdio.h>

void	list_check(t_idk *isdk)
{
	while (isdk->ahead)
	{
		printf("%d, %d\n", isdk->ahead->stk, isdk->actr--);
		isdk->ahead = isdk->ahead->next;
	}
}

t_stack	*create_node(char *value)
{
	t_stack	*tmp;

	if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	tmp->stk = ft_atoi(value);
	tmp->next = NULL;
	return (tmp);
}

void	list_add(t_idk *isdk, char *value)
{
	t_stack	*list;

	list = create_node(value);
	list->next = isdk->ahead;
	isdk->ahead = list;
}

void	create_stacks(t_idk *isdk, int ac, char **av)
{
	int		i;

	i = 1;
	isdk->ahead = NULL;
	isdk->bhead = NULL;
	while (i < ac)
	{
		list_add(isdk, av[i++]);
		isdk->actr++;
	}
}

int		main(int ac, char **av)
{
	t_idk	isdk;

	isdk.actr = 0;
	isdk.bctr = 0;
	if (ac > 1)
	{
		create_stacks(&isdk, ac, av);
		list_check(&isdk);
	}
}