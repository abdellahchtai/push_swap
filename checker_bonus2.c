/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:37:55 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/31 18:45:19 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstclear(t_list **list)
{
	t_list	*move;

	if (!list)
		return ;
	while (*list)
	{
		move = (*list)->next;
		free(*list);
		*list = move;
	}
	*list = NULL;
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_check_duplicat(t_list *head)
{
	t_list	*node;
	int		size;

	size = 0;
	while (head->next)
	{
		node = head->next;
		while (node)
		{
			if (head->content == node->content)
				return (0);
			node = node->next;
		}
		size++;
		head = head->next;
	}
	return (size + 1);
}

t_list	*ft_creat_list_helper(char **arr, t_list **head)
{
	t_list	*list;

	int (j), (flag), (nb);
	j = 0;
	flag = 1;
	while (arr[j])
	{
		nb = ft_atoi(arr[j], &flag);
		if (!flag)
			return (ft_free2(arr),
				ft_lstclear(head), ft_putstr_fd("Error\n", 2), NULL);
		list = ft_lst_new(nb);
		if (!list)
			return (ft_free2(arr),
				ft_lstclear(head), ft_putstr_fd("Error\n", 2), NULL);
		ft_lst_add_back(head, list);
		j++;
	}
	return (*head);
}

t_list	*ft_creat_list(int ac, char **av)
{
	t_list	*node;
	t_list	*head;
	char	**arr;
	int		i;

	i = 1;
	head = NULL;
	while (i < ac)
	{
		arr = ft_split (av[i], ' ');
		if (!arr || !(*arr))
			return (ft_putstr_fd("Error\n", 2),
				ft_lstclear(&head), ft_free2(arr), NULL);
		node = ft_creat_list_helper(arr, &head);
		if (!node)
			return (NULL);
		ft_free2(arr);
		i++;
	}
	return (head);
}
