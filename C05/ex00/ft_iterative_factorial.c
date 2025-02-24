/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alniezgo <alniezgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:45:34 by alniezgo          #+#    #+#             */
/*   Updated: 2025/02/24 16:18:29 by alniezgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int result;
	
	result = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		result *= (nb);
		nb--;
	}
	return (result);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%d\n", ft_iterative_factorial(3));
// }