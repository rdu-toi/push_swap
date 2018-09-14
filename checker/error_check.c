#include "checker.h"

void	error(void)
{
	write(1, "Error\n", 6);
}

void	check_dbls(t_idk *isdk)
{
	t_stack	*check;
	t_stack	*point;

	point = isdk->ahead;
	while (point && point->next)
	{
		check = point->next;
		while (check)
		{
			if (check->stk == point->stk)
			{
				isdk->error = 1;
				break;
			}
			check = check->next;
		}
		if (isdk->error)
			break;
		point = point->next;
	}
	free(check);
	free(point);
}

int		check_num(t_idk *isdk, char *v, int j, int flag)
{
	flag = 0;
	while (v[j])
	{
		if (v[j] == '-')
		{
			flag = 1;
			j++;
		}
		if ((v[j] >= '0' && v[j] <= '9') ||
			(!flag && ft_isspace(v[j])))
		{
			j++;
			flag = 0;
		}
		else
		{
			isdk->error = 1;
			return (0);
		}
	}
	return (1);
}

int		check_args(t_idk *isdk, int ac, char **v)
{
	int		i;
	int		j;
	int		flag;

	i = 1;
	while (i < ac)
	{
		j = 0;
		flag = 0;
		if(!check_num(isdk, v[i], j, flag))
			return (0);
		i++;
	}
	return (1);
}