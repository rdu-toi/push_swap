#include "checker.h"

void    more_print_ops(t_idk *isdk)
{
    while (isdk->ra_true && isdk->ba_dif)
    {
        write(1, "ra\n", 4);
        isdk->ba_dif--;
    }
    while (!isdk->ra_true && isdk->ba_dif)
    {
        write(1, "ra\n", 4);
        isdk->ba_dif--;
    }
    write(1, "pa\n", 3);
    while (isdk->rb_true && isdk->fbb_dif)
}

void    print_ops(t_idk *isdk)
{
    isdk->fbb_dif = isdk->bb_dif + 1;
    while (isdk->ra_true && isdk->rb_true && isdk->ba_dif && isdk->bb_dif)
    {
        write(1, "rrr\n", 4);
        isdk->ba_dif--;
        isdk->bb_dif--;
    }
    while (isdk->rb_true && isdk->bb_dif)
    {
        write(1, "rrb\n", 4);
        isdk->bb_dif--;
    }
    while (!isdk->ra_true && !isdk->rb_true && isdk->ba_dif && isdk->bb_dif)
    {
        write(1, "rr\n", 4);
        isdk->ba_dif--;
        isdk->bb_dif--;
    }
    while (!isdk->rb_true && isdk->bb_dif)
    {
        write(1, "rb\n", 4);
        isdk->bb_dif--;
    }
    more_print_ops(isdk);
}

void    find_num_of_moves(t_idk *isdk)
{
    isdk->b_dif = 0;
    isdk->move_find_b = isdk->bhead;
    isdk->ra_flag = 0;
    isdk->rb_flag = 0;
    if ((isdk->actr + 1 / isdk->a_dif) == 1)
    {
        isdk->ra_flag = 1;
        isdk->a_dif -= isdk->actr + 1;
    }
    while (isdk->move_find_b)
    {
        if (isdk->move_find_a->stk > isdk->move_find_b->stk)
            break;
        isdk->move_find_b = isdk->move_find_b->next;
        isdk->b_dif++;
    }
    if ((isdk->bctr + 1 / isdk->b_dif) == 1)
    {
        isdk->rb_flag = 1;
        isdk->b_dif -= isdk->bctr + 1;
    }
}

void    best_move(t_idk *isdk)
{
    isdk->move_find_a = isdk->ahead;
    isdk->stack_pos = 0;
    isdk->ba_dif = 0;
    isdk->bb_dif = 0;

    while (isdk->move_find_a)
    {
        isdk->a_dif = isdk->stack_pos;
        find_num_of_moves(isdk);
        if (isdk->a_dif + isdk->b_dif < isdk->ba_dif + isdk->bb_dif)
        {
            isdk->ra_true = isdk->ra_flag == 1 ? 1 : 0;
            isdk->rb_true = isdk->rb_flag == 1 ? 1 : 0;
            isdk->best_move = isdk->move_find_a;
            isdk->ba_dif = isdk->a_dif;
            isdk->bb_dif = isdk->b_dif;
        }
        isdk->move_find_a = isdk->move_find_a->next;
        isdk->stack_pos++;
    }
}