/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:15:41 by albealva          #+#    #+#             */
/*   Updated: 2024/06/23 11:40:11 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arg_is_number(char *av)
{
	int i = 0;

	if (av[i] == '\0') // Argumento vacío
		return (0);
	if (is_sign(av[i]) && av[i + 1] != '\0') // Signo seguido de un número
		i++;
	while (av[i])
	{
		if (!is_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	adjusted_nbstr_cmp(const char *s1, const char *s2)
{
	char adj_s1[12];
	char adj_s2[12];

	adjust_number_format(s1, adj_s1);
	adjust_number_format(s2, adj_s2);

	return nbstr_cmp(adj_s1, adj_s2);
}

static int	have_duplicates(char **av)
{
	int i, j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && adjusted_nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	arg_is_zero(char *av)
{
	int i = 0;

	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int is_correct_input(char **av)
{
	int i, nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i])) // Verificar si es un número válido
			return (0);
		nb_zeros += arg_is_zero(av[i]); // Contar ceros
		i++;
	}
	if (nb_zeros > 1) // Verificar si hay más de un cero
		return (0);
	if (have_duplicates(av)) // Verificar duplicados
		return (0);
	return (1);
}