#include "checker.h"

void	rrr(t_idk *isdk)
{
	rra(isdk);
	rrb(isdk);
}

void	KO_error(t_idk *isdk)
{
	if (!ft_strcmp("end", isdk->line))
	{
		write(1, "KO\n", 3);
		isdk->KO = 1;
	}
	else
		isdk->error = 1;
}