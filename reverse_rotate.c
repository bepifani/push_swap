/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:30:16 by bepifani          #+#    #+#             */
/*   Updated: 2022/01/18 17:03:57 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_reverse_rotate(int *massiv)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = massiv[0];
	while (massiv[i + 1] != -1)
	{
		massiv[i] = massiv[i + 1];
		i++;
	}
	massiv[i] = tmp;
}

void	ft_reverse_rotate(int *stack_a, int *stack_b, char rule)
{
	if (rule == 'a' && ft_size_of_mas(stack_a) > 1)
	{
		ft_make_reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
	else if (rule == 'b' && ft_size_of_mas(stack_b) > 1)
	{
		ft_make_reverse_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
	else if (rule == 'r' && ft_size_of_mas(stack_b) > 1
		&& ft_size_of_mas(stack_a) > 1)
	{
		ft_make_reverse_rotate(stack_a);
		ft_make_reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}
