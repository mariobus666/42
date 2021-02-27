/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbus <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:05:05 by mbus              #+#    #+#             */
/*   Updated: 2021/01/21 14:39:10 by mbus             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int		num_words(const char *str, char c)
{
	int		i;
	int		wordcount;

	i = 0;
	wordcount = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			wordcount++;
		while (str[i] != c && str[i])
			i++;
	}
	return (wordcount);
}

static char		*put_word(const char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(word = malloc(i + 1)))
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char			**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**vert;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (!(vert = malloc(sizeof(char *) * num_words(s, c) + 1)))
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			vert[j] = put_word(&s[i], c);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	vert[j] = 0;
	return (vert);
}
