/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:53:50 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/31 16:26:32 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bring_b(t_list **stacka, t_list **stackb, int repeat)
{
	if (repeat > 0)
	{
		while (repeat > 0)
		{
			ft_swap("rb\n", stacka, stackb);
			repeat--;
		}
	}
	else
	{
		repeat = -repeat;
		while (repeat > 0)
		{
			ft_swap("rrb\n", stacka, stackb);
			repeat--;
		}
	}
}

void	ft_bring_a(t_list **stacka, t_list **stackb, int repeat)
{
	if (repeat > 0)
	{
		while (repeat > 0)
		{
			ft_swap("ra\n", stacka, stackb);
			repeat--;
		}
	}
	else
	{
		repeat = -repeat;
		while (repeat > 0)
		{
			ft_swap("rra\n", stacka, stackb);
			repeat--;
		}
	}
}

void	ft_bring_top_both(t_list **stacka, t_list **stackb, int repeat)
{
	if (repeat > 0)
	{
		while (repeat > 0)
		{
			ft_swap("rr\n", stacka, stackb);
			repeat--;
		}
	}
	else
	{
		repeat = -repeat;
		while (repeat > 0)
		{
			ft_swap("rrr\n", stacka, stackb);
			repeat--;
		}
	}
}

void	ft_move_helper(t_list **stacka, t_list **stackb, t_list *node)
{
	if (node->cost_a < 0 && node->cost_b < 0)
	{
		if (node->cost_a > node->cost_b)
		{
			ft_bring_top_both(stacka, stackb, node->cost_a);
			ft_bring_b(stacka, stackb, node->cost_b - node->cost_a);
		}
		else
		{
			ft_bring_top_both(stacka, stackb, node->cost_b);
			ft_bring_a(stacka, stackb, node->cost_a - node->cost_b);
		}
	}
	else
	{
		ft_bring_a(stacka, stackb, node->cost_a);
		ft_bring_b(stacka, stackb, node->cost_b);
	}
}
