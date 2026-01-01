/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:49:54 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/31 21:47:38 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	ft_swap(char *s1, t_list **heada, t_list **headb)
{
	if (ft_strcmp(s1, "sa\n"))
		return (ft_swap_help(heada), 1);
	else if (ft_strcmp(s1, "sb\n"))
		return (ft_swap_help(headb), 1);
	else if (ft_strcmp(s1, "pa\n"))
		return (ft_push_to(headb, heada), 1);
	else if (ft_strcmp(s1, "pb\n"))
		return (ft_push_to(heada, headb), 1);
	else if (ft_strcmp(s1, "ss\n"))
	{
		ft_swap_help(heada);
		ft_swap_help(headb);
		return (1);
	}
	else
		return (ft_continu(s1, heada, headb));
}
