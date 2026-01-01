/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:12:00 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/31 16:26:45 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	cost_to_top(int len, int pos)
{
	if (len / 2 >= pos)
		return (pos);
	return (-1 * (len - pos));
}

int	ft_perfect_move(t_list *stackb)
{
	int		holder;

	int (posb), (p);
	posb = 0;
	p = 0;
	holder = stackb->total;
	while (stackb)
	{
		if (stackb->total < holder)
		{
			holder = stackb->total;
			posb = p;
		}
		p++;
		stackb = stackb->next;
	}
	return (posb);
}

void	ft_move(t_list **stacka, t_list **stackb, int pb)
{
	t_list	*node;
	int		pa;

	node = *stackb;
	pa = 0;
	while (pa < pb)
	{
		node = node->next;
		pa++;
	}
	if (node->cost_a > 0 && node->cost_b > 0)
	{
		if (node->cost_a > node->cost_b)
		{
			ft_bring_top_both(stacka, stackb, node->cost_b);
			ft_bring_a(stacka, stackb, node->cost_a - node->cost_b);
		}
		else
		{
			ft_bring_top_both(stacka, stackb, node->cost_a);
			ft_bring_b(stacka, stackb, node->cost_b - node->cost_a);
		}
	}
	else
		ft_move_helper(stacka, stackb, node);
}

void	ft_cheap_move(t_list **stacka, t_list **stackb)
{
	t_list	*node;

	int (lena), (lenb), (p);
	lena = ft_listsize(*stacka);
	lenb = ft_listsize(*stackb);
	p = 0;
	node = *stackb;
	while (node)
	{
		node->target = ft_small_big(stacka, node->content);
		node->cost_a = cost_to_top(lena, node->target);
		node->cost_b = cost_to_top(lenb, p);
		if (node->cost_a > 0 && node->cost_b > 0)
			node->total = ft_max(node->cost_a, node->cost_b);
		else if (node->cost_a < 0 && node->cost_b < 0)
			node->total = ft_max(ft_abs(node->cost_a), ft_abs(node->cost_b));
		else
			node->total = ft_abs(node->cost_a) + ft_abs(node->cost_b);
		node = node->next;
		p++;
	}
	p = ft_perfect_move(*stackb);
	ft_move(stacka, stackb, p);
}
