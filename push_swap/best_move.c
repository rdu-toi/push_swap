#include "checker.h"

void    push_all_b(t_idk *isdk)
{
    while (isdk->bctr)
        pb(isdk);
}

void    more_print_ops(t_idk *isdk)
{
    while (isdk->ra_true && isdk->ba_dif)
    {
        rra(isdk);
        isdk->ba_dif--;
    }
    while (!isdk->ra_true && isdk->ba_dif)
    {
        ra(isdk);
        isdk->ba_dif--;
    }
    pa(isdk);
    while (isdk->rb_true && isdk->fbb_dif)
    {
        rb(isdk);
        isdk->fbb_dif--;
    }
    while (!isdk->rb_true && (isdk->fbb_dif - 1 != 0))
    {
        rrb(isdk);
        isdk->fbb_dif--;
    }
}

void    print_ops(t_idk *isdk)
{
    isdk->fbb_dif = isdk->bb_dif + 1;
    while (isdk->ra_true && isdk->rb_true && isdk->ba_dif && isdk->bb_dif)
    {
        rrr(isdk);
        isdk->ba_dif--;
        isdk->bb_dif--;
    }
    while (isdk->rb_true && isdk->bb_dif)
    {
        rrb(isdk);
        isdk->bb_dif--;
    }
    while (!isdk->ra_true && !isdk->rb_true && isdk->ba_dif && isdk->bb_dif)
    {
        rr(isdk);
        isdk->ba_dif--;
        isdk->bb_dif--;
    }
    while (!isdk->rb_true && isdk->bb_dif)
    {
        rb(isdk);
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
    if (isdk->a_dif && (isdk->actr + 1 / isdk->a_dif) == 1)
    {
        isdk->ra_flag = 1;
        isdk->a_dif = isdk->actr + 1 - isdk->a_dif;
    }
    while (isdk->move_find_b)
    {
        if (isdk->move_find_a->stk > isdk->move_find_b->stk)
            break;
        isdk->move_find_b = isdk->move_find_b->next;
        isdk->b_dif++;
    }
    if (isdk->b_dif && (isdk->bctr + 1 / isdk->b_dif) == 1)
    {
        isdk->rb_flag = 1;
        isdk->b_dif = isdk->bctr + 1 - isdk->b_dif;
    }
}

void    best_move(t_idk *isdk)
{
    isdk->stack_pos = 0;
    isdk->ba_dif = 999999999;
    isdk->bb_dif = 999999999;
    isdk->ss = 0;
    isdk->rr = 0;
    isdk->rrr = 0;

    if (!isdk->bctr && isdk->actr > 1)
    {
        pa(isdk);
        pa(isdk);
        if (isdk->bhead->stk < isdk->bhead->next->stk)
            sb(isdk);
    }
    isdk->move_find_a = isdk->ahead;
    while (isdk->move_find_a)
    {
        isdk->a_dif = isdk->stack_pos;
        find_num_of_moves(isdk);
        if (isdk->a_dif + isdk->b_dif < isdk->ba_dif + isdk->bb_dif)
        {
            isdk->ra_true = isdk->ra_flag == 1 ? 1 : 0;
            isdk->rb_true = isdk->rb_flag == 1 ? 1 : 0;
            isdk->ba_dif = isdk->a_dif;
            isdk->bb_dif = isdk->b_dif;
        }
        isdk->move_find_a = isdk->move_find_a->next;
        isdk->stack_pos++;
    }
}