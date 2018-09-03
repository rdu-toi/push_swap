#ifndef CHECKER_H
# define CHECKER_H

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct		s_stack
{
	int				stk;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_idk
{
	int				actr;
	int				bctr;
	t_stack			*ahead;
	t_stack			*bhead;
}					t_idk;

#endif