#include "checker.h"

void	sa(t_idk *isdk)
{
	if (isdk->actr > 1)
	{
		int		temp;

		temp = isdk->ahead->stk;
		isdk->ahead->stk = isdk->ahead->next->stk;
		isdk->ahead->next->stk = temp;
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
	if (isdk->actr)
	{
		t_stack		*temp;

		temp = isdk->ahead;
		isdk->ahead = isdk->ahead->next;
		temp->next = isdk->bhead;
		isdk->bhead = temp;
		isdk->actr--;
		isdk->bctr++;
		list_check(isdk);
	}
}

void	pb(t_idk *isdk)
{
	if (isdk->bctr)
	{
		t_stack		*temp;

		temp = isdk->bhead;
		isdk->bhead = isdk->bhead->next;
		temp->next = isdk->ahead;
		isdk->ahead = temp;
		isdk->actr++;
		isdk->bctr--;
		list_check(isdk);
	}
}

void	ra(t_idk *isdk)
{
	if (isdk->actr >= 2)
	{
		t_stack		*temp_tail;
		t_stack		*temp_head;

		temp_tail = isdk->ahead;
		temp_head = isdk->ahead;
		isdk->ahead = isdk->ahead->next;
		while (temp_tail->next)
			temp_tail = temp_tail->next;
		temp_tail->next = temp_head;
		temp_head->next = NULL;
		list_check(isdk);
	}
}

void	rb(t_idk *isdk)
{
	if (isdk->bctr >= 2)
	{
		t_stack		*temp_tail;
		t_stack		*temp_head;

		temp_tail = isdk->bhead;
		temp_head = isdk->bhead;
		isdk->bhead = isdk->bhead->next;
		while (temp_tail->next)
			temp_tail = temp_tail->next;
		temp_tail->next = temp_head;
		temp_head->next = NULL;
		list_check(isdk);
	}
}

void	rr(t_idk *isdk)
{
	ra(isdk);
	rb(isdk);
}

void	rra(t_idk *isdk)
{
	if (isdk->actr >= 2)
	{
		t_stack		*temp_head;
		t_stack		*temp_tail;

		temp_head = isdk->ahead;
		while (isdk->ahead->next)
		{
			temp_tail = isdk->ahead;
			isdk->ahead = isdk->ahead->next;
		}
		isdk->ahead->next = temp_head;
		temp_tail->next = NULL;
		list_check(isdk);
	}
}

void	rrb(t_idk *isdk)
{
	if (isdk->bctr >= 2)
	{
		t_stack		*temp_head;
		t_stack		*temp_tail;

		temp_head = isdk->bhead;
		while (isdk->bhead->next)
		{
			temp_tail = isdk->bhead;
			isdk->bhead = isdk->bhead->next;
		}
		isdk->bhead->next = temp_head;
		temp_tail->next = NULL;
		list_check(isdk);
	}
}

void	rrr(t_idk *isdk)
{
	rra(isdk);
	rrb(isdk);
}

void	ops(t_idk *isdk)
{
	if (!ft_strcmp("sa", isdk->line))
		sa(isdk);
	else if (!ft_strcmp("sb", isdk->line))
		sb(isdk);
	else if (!ft_strcmp("ss", isdk->line))
		ss(isdk);
	else if (!ft_strcmp("pa", isdk->line))
		pa(isdk);
	else if (!ft_strcmp("pb", isdk->line))
		pb(isdk);
	else if (!ft_strcmp("ra", isdk->line))
		ra(isdk);
	else if (!ft_strcmp("rb", isdk->line))
		rb(isdk);
	else if (!ft_strcmp("rr", isdk->line))
		rr(isdk);
	else if (!ft_strcmp("rra", isdk->line))
		rra(isdk);
	else if (!ft_strcmp("rrb", isdk->line))
		rrb(isdk);
	else if (!ft_strcmp("rrr", isdk->line))
		rrr(isdk);
	else
		isdk->error = 1;
}