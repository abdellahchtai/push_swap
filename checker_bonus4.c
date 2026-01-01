/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:52:21 by abchtaib          #+#    #+#             */
/*   Updated: 2026/01/01 23:36:11 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_rotate(t_list **head)
{
	t_list	*node;
	t_list	*node2;

	if (!(*head) || !((*head)->next))
		return (0);
	node = *head;
	node2 = (*head)->next;
	while (node->next)
		node = node->next;
	node->next = *head;
	(*head)->next = NULL;
	*head = node2;
	return (1);
}

int	ft_reverse(t_list **head)
{
	t_list	*node;
	t_list	*node2;

	if (!(*head) || !((*head)->next))
		return (0);
	node = *head;
	while (node->next->next)
		node = node->next;
	node2 = node->next;
	node->next = NULL;
	node2->next = *head;
	*head = node2;
	return (1);
}

int	ft_continu(char *str, t_list **heada, t_list **headb)
{
	if (ft_strcmp(str, "ra\n"))
		return (ft_rotate(heada), 1);
	else if (ft_strcmp(str, "rb\n"))
		return (ft_rotate(headb), 1);
	else if (ft_strcmp(str, "rr\n"))
	{
		ft_rotate(heada);
		ft_rotate(headb);
		return (1);
	}
	else if (ft_strcmp(str, "rra\n"))
		return (ft_reverse(heada), 1);
	else if (ft_strcmp(str, "rrb\n"))
		return (ft_reverse(headb), 1);
	else if (ft_strcmp(str, "rrr\n"))
	{
		ft_reverse(heada);
		ft_reverse(headb);
		return (1);
	}
	return (0);
}

int	list_sorted(t_list *stacka)
{
	if (!stacka)
		return (0);
	while (stacka->next)
	{
		if (stacka->content > stacka->next->content)
			return (0);
		stacka = stacka->next;
	}
	return (1);
}

int	ft_sort(t_list **stacka, t_list **stackb)
{
	char	*str;

	str = get_next_line(0, 1);
	while (str)
	{
		if (!ft_swap(str, stacka, stackb))
			return (free(str), get_next_line(0, 0), 0);
		free(str);
		str = get_next_line(0, 1);
		if (!(*str))
		{
			free(str);
			break ;
		}
	}
	get_next_line(0, 0);
	return (1);
}
