/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alniezgo <alniezgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:25:42 by alniezgo          #+#    #+#             */
/*   Updated: 2025/03/09 19:07:03 by alniezgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int is_charset(char c, char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int count_words(char *str, char *charset)
{
	int i;
	int nb_words;
	int bool;
	
	i = 0;
	nb_words = 0;
	bool = 1;
	while (str[i])
	{
		if (is_charset(str[i], charset))
			bool = 1;
		if (bool == 1 && !is_charset(str[i], charset))
		{
			bool = 0;
			nb_words++;
		}
		i++;
	}
	return (nb_words);
}
int len_words(char *str, char *charset, int i)
{
	int len;

	len = 0;
	while (str[i] && is_charset(str[i], charset))
		i++;
	while (str[i])
	{
		if (is_charset(str[i], charset))
			return (len);
		len++;
		i++;
	}
	return (len);
}

char **ft_split_chaine(char **chaine, int j, char *str, char *charset)
{
	int i;
	int r;
	int size_words;

	i = 0;
	while(j < count_words(str, charset))
	{
		size_words = len_words(str, charset, i);
		chaine[j] = malloc(sizeof(char) * (size_words + 1));
		if (!chaine[j])
			return (NULL);
		while (is_charset(str[i], charset))
			i++;
		r = 0;
		while(r < size_words)
			chaine[j][r++] = str[i++];
		chaine[j][r] = '\0';
		j++;
	}
	chaine[j] = NULL;
	return (chaine);
}
char **ft_split(char *str, char *charset)
{
	char **chaine;

	if (count_words(str, charset) || *str)
	{
		chaine = malloc(sizeof(char *) * (count_words(str, charset) + 1));
		if (!chaine)
			return (NULL);
		if (ft_split_chaine(chaine, 0, str, charset) == NULL)
			return (NULL);
	}
	else
	{
		chaine = malloc(sizeof(char *) * 1);
		if (!chaine)
			return (NULL);
		chaine[0] = 0;
	}
	return (chaine);
}