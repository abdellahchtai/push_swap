/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:29:35 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/31 17:30:53 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				cost_a;
	int				cost_b;
	int				total;
	int				target;
	struct s_list	*next;
}	t_list;

void	ft_putstr_fd(char *s, int fd);
void	ft_free2(char **arr);
void	ft_swap(char *str, t_list **heada, t_list **headb);
int		ft_swap_help(t_list **head);
int		list_sorted(t_list *stacka);
void	ft_lst_add_back(t_list **lst, t_list *new);
void	ft_lst_add_front(t_list **list, t_list *new);
void	ft_lstclear(t_list **list);
void	ft_continu(char *str, t_list **heada, t_list **headb);
int		ft_atoi(char *str, int *flag);
int		ft_check_duplicat(t_list *head);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char *str, char c);
t_list	*ft_creat_list(int ac, char **av);
t_list	*ft_lst_new(int content);
void	ft_sort(t_list **stacka, t_list **stackb, int sizea);
int		ft_small_big(t_list **stacka, int contentb);
int		ft_listsize(t_list *lst);
int		ft_abs(int p);
void	ft_bring_top_both(t_list **stacka, t_list **stackb, int repeat);
void	ft_bring_a(t_list **stacka, t_list **stackb, int repeat);
void	ft_bring_b(t_list **stacka, t_list **stackb, int repeat);
void	ft_move_helper(t_list **stacka, t_list **stackb, t_list *node);
int		cost_to_top(int len, int pos);
int		ft_max(int a, int b);
void	ft_cheap_move(t_list **stacka, t_list **stackb);

#endif