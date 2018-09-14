/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:36:31 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/09/04 13:36:31 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <stdio.h>               ///////////////////

typedef struct		s_stack
{
	int				stk;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_idk
{
	int				actr;
	int				bctr;
	int				error;
	char			*line;
	t_stack			*ahead;
	t_stack			*bhead;
}					t_idk;

int		check_args(t_idk *isdk, int ac, char **v);
void	ops(t_idk *isdk);
void	error(void);
void	check_dbls(t_idk *isdk);
void	list_check(t_idk *isdk); ///////////////////

#endif
