/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:36:26 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/09/04 13:36:27 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	list_check(t_idk *isdk)
{
	int		i = 0;
	while (isdk->ahead)
	{
		printf("%d, %d\n", isdk->ahead->stk, isdk->actr - i++);
		isdk->ahead = isdk->ahead->next;
	}
}

void	sa(t_idk *isdk)
{
	write(2, "ff3\n", 4);
	if (isdk->actr > 1)
	{
		write(2, "ff4\n", 4);
		int		temp;

		printf("%d\n", isdk->ahead->stk);
		//write(2, &isdk->ahead->stk, 1);
		temp = isdk->ahead->stk;
		write(2, &temp, 1);
		write(2, "\n", 1);
		isdk->ahead->stk = isdk->ahead->next->stk;
		isdk->ahead->next->stk = temp;
		// t_stack *temp;

		// temp = isdk->ahead->next;
		// isdk->ahead->next = temp->next;
		// temp->next = isdk->ahead;
		// isdk->ahead = temp;
		list_check(isdk);
	}
}

void	ops(t_idk *isdk)
{
	write(2, "ff1\n", 4);
	if (!ft_strncmp("sa", isdk->line, 2))
	{
		write(2, "ff2\n", 4);
		sa(isdk);
	}
/*	else if (!ft_strncmp("sb\n", isdk->line, 3))
		sb(isdk);
	else if (!ft_strncmp("ss\n", isdk->line, 3))
		ss(isdk);
	else if (!ft_strncmp("pa\n", isdk->line, 3))
		sp(isdk);
	else if (!ft_strncmp("pb\n", isdk->line, 3))
		pb(isdk);
	else if (!ft_strncmp("ra\n", isdk->line, 3))
		ra(isdk);
	else if (!ft_strncmp("rb\n", isdk->line, 3))
		rb(isdk);
	else if (!ft_strncmp("rr\n", isdk->line, 3))
		rr(isdk);
	else if (!ft_strncmp("rra\n", isdk->line, 4))
		rra(isdk);
	else if (!ft_strncmp("rrb\n", isdk->line, 4))
		rrb(isdk);
	else if (!ft_strncmp("rrr\n", isdk->line, 4))
		rrr(isdk);*/
	else
		isdk->error = 1;
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

	list = isdk->ahead;
	isdk->ahead = create_node(value);
	isdk->ahead->next = list;
}

void	create_stacks(t_idk *isdk, int ac, char **av)
{
	int		i;

	i = 1;
	isdk->ahead = NULL;
	isdk->bhead = NULL;
	while (ac > 1)
	{
		list_add(isdk, av[ac-- - 1]);
		isdk->actr++;
	}
}

int		main(int ac, char **av)
{
	t_idk	isdk;

	isdk.error = 0;
	isdk.actr = 0;
	isdk.bctr = 0;
	if (ac > 1)
	{
		create_stacks(&isdk, ac, av);
		list_check(&isdk);
		while(1)
		{
			get_next_line(0, &isdk.line);
			if (isdk.error == 0)
				ops(&isdk);
			else
				break;
		}
	}
}
