/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alniezgo <alniezgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:42:08 by alniezgo          #+#    #+#             */
/*   Updated: 2025/02/21 11:57:01 by alniezgo         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int 	size_dest;

	i = 0;
	j = 0;
	size_dest = ft_strlen(dest);
	while (i < size && dest[i])
		i++;
	if (i == size)
		return (i + ft_strlen(src));
	while (src[j])
	{
		if (j < size - size_dest - 1)
		{
			dest[i] = src[j];
			i++;
		}
		j++;
	}
	dest[i] = '\0';
	return (j + size_dest);
}