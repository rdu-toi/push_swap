#include "checker.h"

void    find_num_of_moves(t_idk *isdk)
{
    isdk->move_find_b = isdk->bhead;

    if ((isdk->actr + 1 / isdk->a_dif) == 1)
    {
        isdk->ra_flag = 1;
        isdk->a_dif -= isdk->actr + 1;
    }
    while (isdk->move_find_b)
    {
        if (isdk->move_find_b->stk > )
    }

}

void    sort(t_idk *isdk)
{
    isdk->move_find_a = isdk->ahead;
    isdk->stack_pos = 0;

    while (isdk->move_find_a)
    {
        isdk->a_dif = isdk->stack_pos;
        find_num_of_moves(isdk);
        if (isdk->a_dif + isdk->b_dif < isdk->ba_dif + isdk->bb_dif)
        {
            isdk->best_move = isdk->move_find_a;
            isdk->ba_dif = isdk->a_dif;
            isdk->bb_dif = isdk->b_dif;
        }
        isdk->move_find_a = isdk->move_find_a->next;
        isdk->stack_pos++;
    }
}