/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_massiv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:48:20 by bepifani          #+#    #+#             */
/*   Updated: 2022/01/18 18:02:10 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
		{
			write(1, "error\n", 6);
			return (0);
		}
	}
	return (1);
}

int	*ft_make_stack_massiv(char **argv, int argc)
{
	int		arr[2];
	long	number;
	int		*massiv;

	massiv = malloc(sizeof (int) * (argc + 1) + 4);
	if (!massiv)
		ft_full_free(massiv);
	arr[0] = 1;
	arr[1] = argc - 2;
	while (argv[arr[0]])
	{
		if (ft_checker(argv[arr[0]]) == 1)
		{
			number = ft_atoi(argv[arr[0]]);
			massiv[arr[1]] = number;
			arr[1]--;
		}
		else
		{
			ft_full_free(massiv);
			return (0);
		}
		arr[0]++;
	}
	return (massiv);
}

int	ft_find_min(int *massiv, int size)
{
	int	i;
	int	nb;

	i = 1;
	nb = massiv[0];
	while (size >= 0)
	{
		if (nb > massiv[i])
			nb = massiv[i];
		i++;
		size--;
	}
	return (nb);
}

int	*ft_massiv_pars(int *massiv, int size)
{
	int	arr[4];
	int	*new_massiv;

	arr[3] = size;
	arr[2] = 0;
	new_massiv = malloc((sizeof (int)) * (size + 1) + 4);
	if (!new_massiv)
		ft_full_free(new_massiv);
	while (size >= 0)
	{
		arr[1] = arr[3];
		arr[0] = ft_find_min(massiv, arr[1] - 1);
		ft_helper(massiv, arr, new_massiv);
		size--;
	}
	new_massiv[arr[3] + 1] = -1;
	return (new_massiv);
}

int	*ft_final_stack(int argc, char **argv)
{
	int	*massiv;
	int	*final_massiv;

	massiv = ft_make_stack_massiv(argv, argc);
	if (!massiv)
	{
		ft_full_free(massiv);
		return (0);
	}
	final_massiv = ft_massiv_pars(massiv, argc - 2);
	if (massiv)
		free (massiv);
	return (final_massiv);
}
