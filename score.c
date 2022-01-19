/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:20:27 by bepifani          #+#    #+#             */
/*   Updated: 2022/01/17 22:22:27 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_score_a(int *stack_a, int *stack_b, int i)
{
	int	score;
	int	j;

	score = 0;
	j = ft_size_of_mas(stack_a) - 1;
	if (stack_b[i] > stack_a[0]
		&& stack_b[i] < stack_a[ft_size_of_mas(stack_a) - 1])
		return (0);
	while (j > 0)
	{
		if (stack_b[i] > stack_a[j] && stack_b[i] < stack_a[j - 1])
			break ;
		score++;
		j--;
	}
	if (score < ft_size_of_mas(stack_a) / 2)
		return (score);
	else
		return (ft_size_of_mas(stack_a) - score);
}

int	ft_find_score_b(int *stack_b, int i)
{
	int	score;
	int	j;

	score = 0;
	j = 0;
	if (i < ft_size_of_mas(stack_b) / 2)
		score = i + 1;
	else
		score = ft_size_of_mas(stack_b) - 1 - i;
	return (score);
}

int	ft_find_score(int *stack_a, int *stack_b, int i)
{
	int	score;

	score = ft_find_score_a(stack_a, stack_b, i) + ft_find_score_b(stack_b, i);
	return (score);
}

int	ft_find_start(int *stack_a, int *stack_b)
{
	int	size;
	int	start;

	size = ft_size_of_mas(stack_b) - 1;
	start = size;
	while (size > 0)
	{
		if (ft_find_score(stack_a, stack_b, start)
			>= ft_find_score(stack_a, stack_b, size - 1))
			start = size - 1;
		size--;
	}
	return (start);
}
