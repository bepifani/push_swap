/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:50:26 by bepifani          #+#    #+#             */
/*   Updated: 2022/01/18 17:59:55 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_make_stack_b(int size)
{
	int	*stack_b;

	stack_b = malloc(sizeof(int) * (size + 1) + 4);
	if (!stack_b)
		return (NULL);
	while (size >= 0)
	{
		stack_b[size] = -1;
		size--;
	}
	return (stack_b);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = ft_final_stack(argc, argv);
		if (!stack_a)
		{
			ft_full_free(stack_a);
			return (0);
		}
		stack_b = ft_make_stack_b(ft_size_of_mas(stack_a));
		if (argc <= 6)
			ft_mini_sort(stack_a, stack_b, argc);
		else
			ft_max_sort(stack_a, stack_b, argc);
	}
	else
		write (1, "Error, need more arguments\n", 27);
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
}
