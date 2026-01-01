/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:54:47 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/22 13:49:04 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_word(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			while (*str != c && *str)
				str++;
			count += 1;
		}
		else
			str++;
	}
	return (count);
}

static int	ft_charalloc(char *str, char **arr, char c)
{
	int (i), (j), (k);
	i = 0;
	j = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i + j] && str[i + j] != c)
		j++;
	if (!j)
		return (0);
	*arr = malloc (j + 1);
	if (!(*arr))
		return (-1);
	k = i + j;
	j = 0;
	while (str[i + j] && str[i + j] != c)
	{
		(*arr)[j] = str[i + j];
		j++;
	}
	(*arr)[j] = '\0';
	return (k);
}

static void	ft_free(char **arr, int word)
{
	while (word >= 0)
	{
		free(arr[word]);
		word--;
	}
	free(arr);
}

char	**ft_split(char *str, char c)
{
	char	**arr;

	int (word), (i), (j);
	if (!str)
		return (NULL);
	word = ft_count_word(str, c);
	arr = malloc ((word + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	word = 0;
	while (str[i])
	{
		j = ft_charalloc(str + i, &arr[word], c);
		if (!j)
			return (arr[word] = NULL, arr);
		else if (j == -1)
			return (ft_free(arr, word), NULL);
		word++;
		i += j;
	}
	arr[word] = NULL;
	return (arr);
}
