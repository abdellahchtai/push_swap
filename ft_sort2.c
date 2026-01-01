/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:29:17 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/31 16:02:38 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_postion(t_list *stack)
{
	int		max;
	int		pos;
	int		p;

	p = 0;
	pos = 0;
	max = stack->content;
	while (stack)
	{
		if (max < stack->content)
		{
			max = stack->content;
			pos = p;
		}
		p++;
		stack = stack->next;
	}
	return (pos);
}

int	ft_min_postion(t_list *stack)
{
	int		min;
	int		pos;
	int		p;

	p = 0;
	pos = 0;
	min = stack->content;
	while (stack)
	{
		if (min > stack->content)
		{
			min = stack->content;
			pos = p;
		}
		p++;
		stack = stack->next;
	}
	return (pos);
}

void	ft_final(t_list **stacka, t_list **stackb)
{
	int		pos;
	int		i;

	pos = ft_min_postion(*stacka);
	i = cost_to_top(ft_listsize(*stacka), pos);
	ft_bring_a(stacka, stackb, i);
}

void	ft_sort_three(t_list **stacka, t_list **stackb)
{
	int		max;

	max = ft_max_postion(*stacka);
	if (max == 0)
		ft_swap("ra\n", stacka, stackb);
	else if (max == 1)
		ft_swap("rra\n", stacka, stackb);
	if ((*stacka)->content > (*stacka)->next->content)
		ft_swap("sa\n", stacka, stackb);
}

void	ft_sort(t_list **stacka, t_list **stackb, int sizea)
{
	if (sizea <= 3)
		return (ft_sort_three(stacka, stackb));
	while (sizea > 3)
	{
		ft_swap("pb\n", stacka, stackb);
		sizea--;
	}
	ft_sort_three(stacka, stackb);
	while (*stackb)
	{
		ft_cheap_move(stacka, stackb);
		ft_swap("pa\n", stacka, stackb);
	}
	return (ft_final(stacka, stackb));
}
