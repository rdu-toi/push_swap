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
	t_stack	*tempa;
	t_stack	*tempb;
	int		a = isdk->actr;
	int		b = isdk->bctr;
	tempa = isdk->ahead;
	tempb = isdk->bhead;
	while (1)
	{
		if (a == 0 && b == 0)
		{
			printf("_    _\n%d    %d\n", isdk->actr, isdk->bctr);
			break;
		}
		if (a >= b && a)
		{
			printf("%d", tempa->stk);
			tempa = tempa->next;
			a--;
		}
		if (b >= a && b)
		{
			printf("    %d\n", tempb->stk);
			tempb = tempb->next;
			b--;
		}
		else
			printf("\n");
	}
}

void	sa(t_idk *isdk)
{
	if (isdk->actr > 1)
	{
		int		temp;

		temp = isdk->ahead->stk;
		isdk->ahead->stk = isdk->ahead->next->stk;
		isdk->ahead->next->stk = temp;
		// t_stack *temp;

		// temp = isdk->ahead->next;
		// isdk->ahead->next = temp->next;
		// temp->next = isdk->ahead;=
		// isdk->ahead = temp;
		list_check(isdk);
	}
}

void	sb(t_idk *isdk)
{
	if (isdk->bctr > 1)
	{
		int		temp;

		temp = isdk->bhead->stk;
		isdk->bhead->stk = isdk->bhead->next->stk;
		isdk->bhead->next->stk = temp;
		// t_stack *temp;

		// temp = isdk->ahead->next;
		// isdk->ahead->next = temp->next;
		// temp->next = isdk->ahead;=
		// isdk->ahead = temp;
		list_check(isdk);
	}
}

void	ss(t_idk *isdk)
{
	sa(isdk);
	sb(isdk);
}

void	pa(t_idk *isdk)
{
	
}

void	ops(t_idk *isdk)
{
	if (!ft_strncmp("sa", isdk->line, 2))
		sa(isdk);
	else if (!ft_strncmp("sb", isdk->line, 2))
		sb(isdk);
	else if (!ft_strncmp("ss\n", isdk->line, 3))
		ss(isdk);
	else if (!ft_strncmp("pa\n", isdk->line, 3))
		pa(isdk);
	/*else if (!ft_strncmp("pb\n", isdk->line, 3))
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
	isdk->ahead = NULL;
	isdk->bhead = NULL;
	isdk->error = 0;
	isdk->actr = 0;
	isdk->bctr = 0;
	while (ac > 1)
	{
		list_add(isdk, av[ac-- - 1]);
		isdk->actr++;
	}
}

int		main(int ac, char **av)
{
	t_idk	isdk;

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
