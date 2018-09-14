#include "checker.h"

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
			printf("=    =\n%d    %d\n=    =\n", isdk->actr, isdk->bctr);
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