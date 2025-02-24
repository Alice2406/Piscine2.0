/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alniezgo <alniezgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:52:18 by alniezgo          #+#    #+#             */
/*   Updated: 2025/02/19 16:42:21 by alniezgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_init_max(int *max, int n)
{
	int	i;
	int	max_nb;

	i = n - 1;
	max_nb = 9;
	while (i >= 0)
	{
		max[i--] = max_nb--;
	}
	return (*max);
}

int	ft_init_tab(int *tab, int n)
{
	int	i;
	int	nb;

	i = -1;
	nb = 0;
	while (++i < n)
		tab[i] = nb++;
	tab[i] = '\0';
	return (*tab);
}

void	ft_print_tab(int *tab, int n, int index)
{
	int	i;

	i = -1;
	if (index != 0)
		write(1, ", ", 2);
	while (++i < n)
	{
		tab[i] = tab[i] + '0';
		write(1, &tab[i], 1);
		tab[i] = tab[i] - '0';
	}
}

void	ft_get_next_tab(int *tab, int *max, int n)
{
	int	i;

	i = n - 1;
	ft_print_tab(tab, n, 0);
	while (tab[0] != max[0])
	{
		while (tab[i] == max[i])
			i--;
		tab[i]++;
		while (i < n - 1)
		{
			i++;
			tab[i] = tab[i - 1] + 1;
		}
		ft_print_tab(tab, n, 1);
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];
	int	max[10];

	ft_init_tab(tab, n);
	ft_init_max(max, n);
	ft_get_next_tab(tab, max, n);
}
