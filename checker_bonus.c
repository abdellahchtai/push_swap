/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:38:37 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/31 22:44:52 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*ft_lst_new(int content)
{
	t_list	*head;

	head = malloc (sizeof(t_list));
	if (!head)
		return (NULL);
	return ((head->content = content), (head->next = NULL), head);
}

void	ft_lst_add_back(t_list **lst, t_list *new)
{
	t_list	*move;

	if (!new || !lst)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	move = *lst;
	while (move->next)
		move = move->next;
	move->next = new;
}

int	ft_atoi(char *str, int *flag)
{
	long	nb;
	int		signe;

	nb = 0;
	signe = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	if (!(*str))
		return (*flag = 0, 0);
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (*flag = 0, 0);
		nb = nb * 10 + (*str - '0');
		if (nb * signe < INT_MIN || nb * signe > INT_MAX)
			return (*flag = 0, 0);
		str++;
	}
	return (nb * signe);
}

void	ft_free2(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	main(int ac, char **av)
{
	t_list	*stacka;
	t_list	*stackb;
	int		size;

	if (ac < 2)
		return (0);
	stackb = NULL;
	stacka = ft_creat_list(ac, av);
	if (!stacka)
		return (1);
	size = ft_check_duplicat(stacka);
	if (!size)
		return (ft_lstclear(&stacka), ft_putstr_fd("Error\n", 2), 1);
	if (!ft_sort(&stacka, &stackb))
		return (ft_lstclear(&stacka)
			, ft_lstclear(&stackb), ft_putstr_fd("Error\n", 2), 1);
	if (list_sorted(stacka) && !stackb)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (ft_lstclear(&stacka), ft_lstclear(&stackb), 0);
}
