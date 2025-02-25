/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alniezgo <alniezgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:01:49 by alniezgo          #+#    #+#             */
/*   Updated: 2025/02/25 10:13:42 by alniezgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while(str[++i])
		write(1, &str[i], 1);
}

int	main(int ac, char **av)
{
	int diff;
	int i;
	char *tmp;

	i = 2;
	if (ac < 2)
		return (0);
	while(av[i])
	{
		diff = ft_strcmp(av[i - 1], av[i]);
		if (diff > 0)
		{
			tmp = av[i];
			av[i] = av[i - 1];
			av[i - 1] = tmp;
			i = 2;
		}
		i++;
	}
	i = 0;
	while (av[++i])
	{
		ft_putstr(av[i]);
		write(1, "\n", 1);
	}
}