/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alniezgo <alniezgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:59:27 by alniezgo          #+#    #+#             */
/*   Updated: 2025/02/25 10:00:46 by alniezgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while(str[++i])
		write(1, &str[i], 1);
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac > 1)
	{
		while(av[i])
			i++;
		while(--i > 0)
		{
			ft_putstr(av[i]);
			write(1, "\n", 1);
		}
	}
	return (0);
}