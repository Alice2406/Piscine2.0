/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alniezgo <alniezgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:57:32 by alniezgo          #+#    #+#             */
/*   Updated: 2025/03/09 18:10:49 by alniezgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
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

long	ft_get_nb(char *base, int i, char *str)
{
	int j;
	int size;
	long nb;

	j = 0;
	nb = 0;
	size = ft_strlen(base);
	while(index_base(str[i], base) != -1)
	{
		nb = nb * size + index_base(str[i], base);
		j++;
		i++;
	}
	return (nb);
}

long	ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	long nb;

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
	nb = ft_get_nb(base, i, str);
	return (nb * sign);
}

void	ft_itoa_base(long nb, char *base, char *str, int i)
{
	int size_base;

	size_base = ft_strlen(base);
	if (nb < 0)
	{
		str[i] = '-';
		nb *= (-1);
		i++;
	}
	if (nb < size_base)
	{
		str[i] = base[nb];
		str[i + 1] = '\0';
	}
	else
	{
		ft_itoa_base(nb / size_base, base, str, i);
		ft_itoa_base(nb % size_base, base, str, ft_strlen(str));
	}
}