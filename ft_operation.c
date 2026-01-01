/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:16:09 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/26 19:53:51 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (s1 && s2 && *s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (s1 && s2 && (*s1 == *s2))
		return (1);
	return (0);
}

void	ft_lst_add_front(t_list **list, t_list *new)
{
	if (!new || !list)
		return ;
	new->next = *list;
	*list = new;
}

int	ft_push_to(t_list **heada, t_list **headb)
{
	t_list	*node;

	if (!(*heada))
		return (0);
	node = (*heada)->next;
	(*heada)->next = NULL;
	ft_lst_add_front(headb, (*heada));
	(*heada) = node;
	return (1);
}

int	ft_swap_help(t_list **head)
{
	int	tmp;

	if (!(*head) || !((*head)->next))
		return (0);
	tmp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = tmp;
	return (1);
}

void	ft_swap(char *s1, t_list **heada, t_list **headb)
{
	if (ft_strcmp(s1, "sa\n"))
	{
		if (ft_swap_help(heada))
			ft_putstr_fd(s1, 1);
	}
	else if (ft_strcmp(s1, "sb\n"))
	{
		if (ft_swap_help(headb))
			ft_putstr_fd(s1, 1);
	}
	else if (ft_strcmp(s1, "pa\n"))
	{
		if (ft_push_to(headb, heada))
			ft_putstr_fd(s1, 1);
	}
	else if (ft_strcmp(s1, "pb\n"))
	{
		if (ft_push_to(heada, headb))
			ft_putstr_fd(s1, 1);
	}
	else
		ft_continu(s1, heada, headb);
}
