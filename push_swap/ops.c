#include "checker.h"

void	sa(t_idk *isdk)
{
	if (isdk->actr > 1)
	{
		int		temp;

		temp = isdk->ahead->stk;
		isdk->ahead->stk = isdk->ahead->next->stk;
		isdk->ahead->next->stk = temp;
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
	}
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
}