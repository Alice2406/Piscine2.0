/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alniezgo <alniezgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:36:00 by alniezgo          #+#    #+#             */
/*   Updated: 2025/03/09 18:00:02 by alniezgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int norme_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || base[i] < 32 || base[i] >= 127
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long nb;
	char *str;
	
	if (!norme_base(base_from) || !norme_base(base_to))
		return (NULL);
	str = malloc(sizeof(char) * 34);
	if (!str)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	if (nb < -2147483648 || nb > 2147483647)
	{
		free(str);
		return (NULL);
	}
	ft_itoa_base(nb, base_to, str, 0);
	return (str);
}