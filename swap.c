/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:31:45 by bepifani          #+#    #+#             */
/*   Updated: 2022/01/18 17:03:39 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_swap(int *massiv)
{
	int	i;
	int	tmp;

	i = ft_size_of_mas(massiv);
	tmp = massiv[i - 1];
	massiv[i - 1] = massiv[i - 2];
	massiv[i - 2] = tmp;
}

int	ft_size_of_mas(int *massiv)
{
	int	i;

	i = 0;
	while (massiv[i] != -1)
		i++;
	return (i);
}

void	ft_swap(int *stack_a, int *stack_b, char rule)
{
	if (rule == 'a' && ft_size_of_mas(stack_a) > 1)
	{
		ft_make_swap(stack_a);
		write(1, "sa\n", 3);
	}
	else if (rule == 'b' && ft_size_of_mas(stack_b) > 1)
	{
		ft_make_swap(stack_b);
		write(1, "sb\n", 3);
	}
	else if (rule == 's' && ft_size_of_mas(stack_a) > 1
		&& ft_size_of_mas(stack_b) > 1)
	{
		ft_make_swap(stack_a);
		ft_make_swap(stack_b);
		write(1, "ss\n", 3);
	}
}
