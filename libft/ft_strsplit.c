/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:16:31 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/18 18:05:08 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;
	char	prev;

	i = 0;
	count = 0;
	prev = '\0';
	while (s[i])
	{
		if (s[i] != c && (prev == c || prev == '\0'))
			count++;
		prev = s[i];
		i++;
	}
	return (count);
}

static void		ft_fill_words_len(int *words_lengths, char const *s, char c)
{
	size_t	i;
	int		j;
	char	prev;

	prev = '\0';
	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] != c && (prev == c || prev == '\0'))
		{
			j++;
			words_lengths[j] = 0;
			while (s[i] && s[i] != c)
			{
				words_lengths[j]++;
				i++;
			}
			if (s[i] == '\0')
				break ;
		}
		prev = s[i];
		i++;
	}
}

static char		**ft_alloc_words(const int *words_lengths, size_t size)
{
	char		**words;
	size_t		i;

	i = 0;
	words = (char**)malloc(sizeof(char*) * (size + 1));
	if (!words)
		return (NULL);
	while (i < size)
	{
		words[i] = (char*)malloc(sizeof(char) * (words_lengths[i] + 1));
		if (!words[i])
		{
			ft_free_mtrx(words, i);
			return (NULL);
		}
		i++;
	}
	return (words);
}

static void		ft_split(char **words,
						int *words_lengths, char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	prev;

	j = -1;
	i = 0;
	prev = '\0';
	while (s[i])
	{
		if ((prev == c || prev == '\0') && s[i] != c)
		{
			j++;
			ft_strncpy(words[j], s + i, words_lengths[j]);
			words[j][words_lengths[j]] = '\0';
		}
		prev = s[i];
		i++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	size_t	words_count;
	int		*words_lengths;

	if (!s)
		return (NULL);
	words_count = ft_count_words(s, c);
	words_lengths = (int*)malloc(sizeof(int) * words_count);
	if (!words_lengths)
		return (NULL);
	ft_fill_words_len(words_lengths, s, c);
	words = ft_alloc_words(words_lengths, words_count);
	if (!words)
	{
		free(words_lengths);
		return (NULL);
	}
	ft_split(words, words_lengths, s, c);
	free(words_lengths);
	words[words_count] = NULL;
	return (words);
}
