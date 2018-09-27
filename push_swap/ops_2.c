#include "checker.h"

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
	}
}