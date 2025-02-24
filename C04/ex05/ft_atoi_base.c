/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alniezgo <alniezgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:19:07 by alniezgo          #+#    #+#             */
/*   Updated: 2025/02/24 15:35:47 by alniezgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

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
			|| base[i] == ' ' || base[i] < 32 || base[i] >= 127)
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

int index_base(char c, char *base)
{
	int i;

	i = 0;
	while(c != base[i] && base[i])
		i++;
	if (!base[i])
		return (-1);
	return (i);
}

void	ft_get_nb(int *nb, char *base, int i, char *str)
{
	int j;
	int size;

	j = 0;
	size = ft_strlen(base);
	while(index_base(str[i], base) != -1)
	{
		*nb = *nb * size + index_base(str[i], base);
		j++;
		i++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int nb;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] =='\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	ft_get_nb(&nb, base, i, str);
	return (nb * sign);
}

#include <stdio.h>

int main()
{
	printf("%d\n", ft_atoi_base("10", "01"));
}