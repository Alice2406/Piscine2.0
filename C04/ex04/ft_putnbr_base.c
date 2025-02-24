/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alniezgo <alniezgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:01:38 by alniezgo          #+#    #+#             */
/*   Updated: 2025/02/24 15:23:48 by alniezgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
			|| base[i] < 32 || base[i] >= 127)
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

void	ft_putnbr_base(int nbr, char *base)
{
	long int nbr_long;
	int size;
	
	nbr_long = nbr;
	size = ft_strlen(base);
	if (!norme_base(base))
		return ;
	if (nbr_long < 0)
	{
		nbr_long *= (-1);
		write(1, "-", 1);
	}
	if (nbr_long <= size)
		ft_putchar(base[nbr_long]);
	else
	{
		ft_putnbr_base(nbr_long / size, base);
		ft_putnbr_base(nbr_long % size, base);
	}
}