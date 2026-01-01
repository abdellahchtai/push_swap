/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:41:01 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/31 23:02:48 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_continue3(char *str, t_list **heada, t_list **headb)
{
	if (ft_strcmp(str, "rrb\n"))
	{
		if (ft_reverse(headb))
			ft_putstr_fd(str, 1);
	}
	else if (ft_strcmp(str, "rrr\n"))
	{
		if (ft_reverse(heada) | ft_reverse(headb))
			ft_putstr_fd(str, 1);
	}
	else if (ft_strcmp(str, "ss\n"))
	{
		if (ft_swap_help(heada) | ft_swap_help(headb))
			ft_putstr_fd(str, 1);
	}
}

void	ft_continu(char *str, t_list **heada, t_list **headb)
{
	if (ft_strcmp(str, "ra\n"))
	{
		if (ft_rotate(heada))
			ft_putstr_fd(str, 1);
	}
	else if (ft_strcmp(str, "rb\n"))
	{
		if (ft_rotate(headb))
			ft_putstr_fd(str, 1);
	}
	else if (ft_strcmp(str, "rr\n"))
	{
		if (ft_rotate(heada) | ft_rotate(headb))
			ft_putstr_fd(str, 1);
	}
	else if (ft_strcmp(str, "rra\n"))
	{
		if (ft_reverse(heada))
			ft_putstr_fd(str, 1);
	}
	else
		ft_continue3(str, heada, headb);
}

int	list_sorted(t_list *stacka)
{
	while (stacka->next)
	{
		if (stacka->content > stacka->next->content)
			return (0);
		stacka = stacka->next;
	}
	return (1);
}
