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
	int		i;

	i = 0;
	while (v[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (v[i] == 'v')
			break;
		if (i == 0 || (v[i] == ' ' && v[i - 1] != ' '))
		{
			list = isdk->ahead;
			isdk->ahead = create_node(ft_atoi(&(v[i])));
			isdk->ahead->next = list;
			isdk->actr++;
		}
		i--;
	}
}

void	create_stacks(t_idk *isdk, int ac, char **av)
{
	isdk->ahead = NULL;
	isdk->bhead = NULL;
	isdk->error = 0;
	isdk->actr = 0;
	isdk->bctr = 0;
	isdk->KO = 0;
	while (ac > 1)
		list_add(isdk, av[ac-- - 1]);
}

void	free_error(t_idk *isdk)
{
	if (isdk->ahead)
		free(isdk->ahead);
	if (isdk->bhead)
		free(isdk->bhead);
	if (isdk->error)
		write(1, "Error\n", 6);
}

int		main(int ac, char **av)
{
	t_idk	isdk;

	if (ac > 1 && check_args(&isdk, ac, av))
	{
		create_stacks(&isdk, ac, av);
		check_dbls(&isdk);
		if (!isdk.error)
		if (isdk.list_print)
			list_check(&isdk);
		while(!isdk.error)
		{
			get_next_line(0, &isdk.line);
			ops(&isdk);
			free(isdk.line);
			if ((check_odr(&isdk) && !isdk.bctr) || isdk.KO)
				break;
		}
	}
	free_error(&isdk);
}
