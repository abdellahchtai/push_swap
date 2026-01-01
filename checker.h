/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:44:11 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/31 21:46:28 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_list
{
	int				content;
	int				cost_a;
	int				cost_b;
	int				total;
	int				target;
	struct s_list	*next;
}	t_list;

t_list	*ft_creat_list(int ac, char **av);
void	ft_putstr_fd(char *s, int fd);
void	ft_lstclear(t_list **list);
int		ft_check_duplicat(t_list *head);
char	**ft_split(char *str, char c);
void	ft_free2(char **arr);
int		ft_atoi(char *str, int *flag);
int		ft_strcmp(char *s1, char *s2);
int		ft_swap(char *s1, t_list **heada, t_list **headb);
void	ft_lst_add_front(t_list **list, t_list *new);
int		ft_strcmp(char *s1, char *s2);
int		list_sorted(t_list *stacka);
int		ft_continu(char *str, t_list **heada, t_list **headb);
t_list	*ft_lst_new(int content);
void	ft_lst_add_back(t_list **lst, t_list *new);
int		ft_sort(t_list **stacka, t_list **stackb);

#endif