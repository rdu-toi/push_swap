#include "checker.h"

void	space(t_idk *isdk, int flag)
{
	int		spaces;

	spaces = 1;
	while (spaces <= ft_nbrlen(isdk->actr) && flag)
	{
		write(1, "=", 1);
		spaces++;
	}
	while (spaces + ft_nbrlen(isdk->actr) <= 15 && !flag)
	{
		write(1, " ", 1);
		spaces++;
	}
}

void	end(t_idk *isdk)
{
	space(isdk, 1);
	space(isdk, 0);
	space(isdk, 1);
	write(1,"\n", 1);
	ft_putnbr(isdk->actr);
	space(isdk, 0);
	ft_putnbr(isdk->bctr);
	write(1, "\n", 1);
	space(isdk, 1);
	space(isdk, 0);
	space(isdk, 1);
	write(1,"\n", 1);
}

void	lista(t_idk *isdk)
{
	ft_putnbr(isdk->tempa->stk);
	isdk->a--;
	isdk->list_flag = 1;
}

void	listb(t_idk *isdk)
{
	int		spaces;

	spaces = 1;
	while (isdk->list_flag && spaces + ft_nbrlen(isdk->tempa->stk) <= 15)
	{
		write(1, " ", 1);
		spaces++;
	}
	while (!isdk->list_flag && spaces <= 15)
	{
		write(1, " ", 1);
		spaces++;
	}
	ft_putnbr(isdk->tempb->stk);
	isdk->b--;
	isdk->tempb = isdk->tempb->next;
}

void	list_check(t_idk *isdk)
{
	isdk->tempa = isdk->ahead;
	isdk->tempb = isdk->bhead;
	isdk->a = isdk->actr;
	isdk->b = isdk->bctr;
	while (1)
	{
		isdk->list_flag = 0;
		if (isdk->a == 0 && isdk->b == 0)
		{
			end(isdk);
			break;
		}
		if (isdk->a >= isdk->b && isdk->a)
			lista(isdk);
		if (isdk->b > isdk->a && isdk->b)
			listb(isdk);
		if (isdk->list_flag)
			isdk->tempa = isdk->tempa->next;
		write(1, "\n", 1);
	}
}

// void	list_check(t_idk *isdk)
// {
// 	t_stack	*tempa;
// 	t_stack	*tempb;
// 	int		a = isdk->actr;
// 	int		b = isdk->bctr;
// 	tempa = isdk->ahead;
// 	tempb = isdk->bhead;
// 	while (1)
// 	{
// 		if (a == 0 && b == 0)
// 		{
// 			printf("=    =\n%d    %d\n=    =\n", isdk->actr, isdk->bctr);
// 			break;
// 		}
// 		if (a >= b && a)
// 		{
// 			printf("%d", tempa->stk);
// 			tempa = tempa->next;
// 			a--;
// 		}
// 		if (b > a && b)
// 		{
// 			printf("    %d", tempb->stk);
// 			tempb = tempb->next;
// 			b--;
// 		}
// 		printf("\n");
// 	}
// }