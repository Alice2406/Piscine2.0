/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alniezgo <alniezgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:24:36 by alniezgo          #+#    #+#             */
/*   Updated: 2025/02/24 16:29:49 by alniezgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	while(power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%d\n", ft_iterative_power(5, 1));
// }