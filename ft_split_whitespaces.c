/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:40:28 by cdupuis           #+#    #+#             */
/*   Updated: 2018/02/24 18:02:49 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		count_words(char *str)
{
	int words;

	words = 0;
	while (*str != '\0')
	{
		while ((*str == ' ' || *str == '\t' || *str == '\n'))
			str++;
		if (*str == '\0')
			return (words);
		words++;
		while (!(*str == ' ' || *str == '\t' || *str == '\n') && *str != '\0')
			str++;
	}
	return (words);
}

int		*count_char(char *str, int words)
{
	int cpt;
	int *tab;
	int j;

	cpt = 0;
	tab = (int *)malloc(sizeof(*tab) * words);
	j = 0;
	while (*str != '\0')
	{
		while ((*str == ' ' || *str == '\t' || *str == '\n') && *str != '\0')
			str++;
		while (!(*str == ' ' || *str == '\t' || *str == '\n') && *str != '\0')
		{
			cpt++;
			str++;
		}
		tab[j] = cpt;
		cpt = 0;
		j++;
		if (j >= words)
			return (tab);
		str++;
	}
	return (tab);
}

char	**blank_tab(int *tab, int words)
{
	char	**blank;
	int		i;

	i = 0;
	blank = (char**)malloc(sizeof(char*) * (words + 1));
	while (i < words)
	{
		blank[i] = (char*)malloc(sizeof(char) * (tab[i]) + 1);
		i++;
	}
	blank[i] = (char*)malloc(sizeof(char) * 1);
	if (blank == NULL)
		return (NULL);
	return (blank);
}

void	full_tab(char **blank, char *str, int *tab, int words)
{
	int j;
	int k;
	int i;

	i = 0;
	j = 0;
	k = 0;
	while (i < words)
	{
		while (j < tab[i])
		{
			while (str[k] == ' ' || str[k] == '\t' || str[k] == '\n')
				k++;
			blank[i][j] = str[k];
			j++;
			k++;
		}
		blank[i][j] = '\0';
		j = 0;
		i++;
	}
	blank[i] = 0;
}

char	**ft_split_whitespaces(char *str)
{
	int		words;
	int		*tab;
	char	**blank;

	words = count_words(str);
	tab = count_char(str, words);
	blank = blank_tab(tab, words);
	full_tab(blank, str, tab, words);
	return (blank);
}
