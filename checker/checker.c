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

t_stack	*create_node(int value)
{
	t_stack	*tmp;

	if (!(tmp = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	tmp->stk = value;
	tmp->next = NULL;
	return (tmp);
}

void	list_add(t_idk *isdk, char *v)
{
	t_stack	*list;
	size_t	i;

	i = 0;
	while (v[i])
	{
		if (v[i] == '-' || (v[i] >= '0' && v[i] <= '9'))
		{
			list = isdk->ahead;
			isdk->ahead = create_node(ft_atoi(&(v[i])));
			isdk->ahead->next = list;
			i += ft_strlenc(&v[i], ' ');
			isdk->actr++;
		}
		else if (v[i] == ' ')
			i++;
	}
}

void	create_stacks(t_idk *isdk, int ac, char **av)
{
	isdk->ahead = NULL;
	isdk->bhead = NULL;
	isdk->error = 0;
	isdk->actr = 0;
	isdk->bctr = 0;
	while (ac > 1)
		list_add(isdk, av[ac-- - 1]);
}

int		main(int ac, char **av)
{
	t_idk	isdk;

	if (ac > 1 && check_args(&isdk, ac, av))
	{
		create_stacks(&isdk, ac, av);
		list_check(&isdk);
		check_dbls(&isdk);
			while (1);
		while(!isdk.error)
		{
			get_next_line(0, &isdk.line);
			ops(&isdk);
			if (!ft_strcmp("end", isdk->line))
			if (check_odr(&isdk) && !isdk.bctr)
				break;
			free(isdk.line);
		}
	}
	if (isdk.error)
	{
		free(isdk.ahead);
		free(isdk.bhead);
		error();
	}
}
