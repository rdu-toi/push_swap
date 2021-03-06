#include "checker.h"

int		check_odr(t_idk *isdk)
{
	t_stack	*temp;

	temp = isdk->ahead;
	while (temp && temp->next)
	{
		if (temp->stk > temp->next->stk)
			return (0);
		temp = temp->next;
	}
	if (!isdk->bctr)
	{
		write(1, "OK\n", 3);
		return (1);
	}
	return (0);
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
}

int		check_flags(t_idk *isdk, char *v, int j)
{
	if (v[j] == 'v' && v[j + 1] == '\0')
	{
		isdk->list_print = 1;
		return (1);
	}
	if (v[j] == 'o' && v[j + 1] == '\0')
	{
		isdk->ops_print = 1;
		return (1);
	}
	if (v[j] == 'c' && v[j + 1] == '\0')
	{
		isdk->col_print = 1;
		return (1);
	}
	return (0);
}

int		check_num(t_idk *isdk, char *v, int i, int j)
{
	isdk->s = ft_strsplit(v, ' ');
	while (isdk->s[i])
	{
		j = 0;
		isdk->flag = 0;
		if (isdk->s[i][j] == '-')
			j++;
		while (isdk->s[i][j])
		{
			if (j == 1 && isdk->s[i][1] != '\0')
			{
				if (isdk->s[i][j - 1] == '-' && check_flags(isdk, isdk->s[i], j))
					isdk->flag = 1;
			}
			if (!(isdk->s[i][j] >= '0' && isdk->s[i][j] <= '9') && !isdk->flag)
				return (0);
			j++;
		}
		if (ft_strcmp(isdk->s[i], ft_itoa(ft_atoi(isdk->s[i]))) != 0 && !isdk->flag)
			return (0);
		i++;
	}
	return (1);
}

int		check_args(t_idk *isdk, int ac, char **v)
{
	isdk->ahead = NULL;
	isdk->bhead = NULL;
	
	if (ac > 1)
	{
		int		i;
		int		j;
		int		k;

		isdk->list_print = 0;
		i = 1;
		j = 0;
		k = 0;
		while (i < ac)
		{
			if(!check_num(isdk, v[i], j, k))
			{
				isdk->error = 1;
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}