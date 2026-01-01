/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 09:52:44 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/31 16:09:59 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int p)
{
	if (p < 0)
		return (-p);
	return (p);
}

int	ft_listsize(t_list *lst)
{
	int		l;

	l = 0;
	while (lst)
	{
		lst = lst->next;
		l++;
	}
	return (l);
}

int	ft_small(t_list *stacka)
{
	int (posa), (p), (holder);
	posa = 0;
	p = 0;
	holder = stacka->content;
	while (stacka)
	{
		if (stacka->content < holder)
		{
			holder = stacka->content;
			posa = p;
		}
		p++;
		stacka = stacka->next;
	}
	return (posa);
}

int	ft_small_big_helper(t_list *node, int contentb, int holder, int p)
{
	int		posa;

	posa = p;
	while (node)
	{
		if (node->content > contentb
			&& node->content - contentb < holder)
		{
			holder = node->content - contentb;
			posa = p;
		}
		p++;
		node = node->next;
	}
	return (posa);
}

int	ft_small_big(t_list **stacka, int contentb)
{
	t_list	*node;

	int (posa), (p), (holder);
	posa = 0;
	p = 0;
	node = *stacka;
	while (node)
	{
		if (node->content > contentb)
		{
			holder = node->content - contentb;
			posa = p;
			break ;
		}
		p++;
		node = node->next;
	}
	if (!node)
		return (ft_small(*stacka));
	holder = node->content - contentb;
	return (ft_small_big_helper(node, contentb, holder, p));
}
