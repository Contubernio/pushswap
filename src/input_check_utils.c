/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:15:34 by albealva          #+#    #+#             */
/*   Updated: 2024/06/23 11:39:59 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	nbstr_cmp(const char *s1, const char *s2)
{
	int	i, j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

void adjust_number_format(const char *str, char *new_str)
{
	int i = 0, j = 0;

	// Si hay un signo al inicio
	if (is_sign(str[0]))
	{
		new_str[j++] = str[i++];
	}

	// Saltar ceros iniciales
	while (str[i] == '0')
		i++;

	// Si todos son ceros, poner uno
	if (str[i] == '\0')
		new_str[j++] = '0';

	// Copiar el resto
	while (str[i])
		new_str[j++] = str[i++];
	
	new_str[j] = '\0';  // Terminar la cadena
}