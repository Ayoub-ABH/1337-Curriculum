/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_liss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:59:02 by aait-bab          #+#    #+#             */
/*   Updated: 2024/03/23 23:01:37 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_tabs(int **leng_tab, int **index_tab, int size)
{
	int	i;

	i = 0;
	*leng_tab = (int *)malloc(sizeof(int) * size);
	if (!*leng_tab)
		return ;
	*index_tab = (int *)malloc(sizeof(int) * size);
	if (!*index_tab)
	{
		free(*leng_tab);
		return ;
	}
	while (i < size)
	{
		*(*leng_tab + i) = 1;
		*(*index_tab + i) = -1;
		i++;
	}
}

void	get_max_len(int *ln_t, int size, int *j)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (ln_t[i] > max)
		{
			max = ln_t[i];
			*j = i;
		}
		i++;
	}
}

int	*fill_lis_seq(t_stack *a, int *index_tab, int seq_maxlen, int j)
{
	int	*liss_seq;
	int	i;

	i = 0;
	liss_seq = (int *)malloc(sizeof(int) * a->size);
	if (!liss_seq)
		return (NULL);
	liss_seq[a->size - 1] = seq_maxlen;
	while (j != -1)
	{
		liss_seq[--seq_maxlen] = a->args[j];
		j = index_tab[j];
		i++;
	}
	return (liss_seq);
}

int	*get_liss(t_stack *a)
{
	int		*lis_seq;
	int		*ln_t;
	int		*in_t;
	int		i;
	int		j;

	init_tabs(&ln_t, &in_t, a->size);
	i = 1;
	while (i < a->size)
	{
		j = 0;
		while (j < i)
		{
			if (a->args[j] < a->args[i] && ln_t[i] < ln_t[j] + 1)
			{
				ln_t[i] = ln_t[j] + 1;
				in_t[i] = j;
			}
			j++;
		}
		i++;
	}
	get_max_len(ln_t, a->size, &j);
	lis_seq = fill_lis_seq(a, in_t, ln_t[j], j);
	return (free(ln_t), free(in_t), lis_seq);
}
