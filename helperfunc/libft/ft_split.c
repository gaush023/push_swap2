/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:43:44 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/02 00:56:11 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	g_wc(const char *str, char c)
{
	size_t	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}

static char	*f_nw(char const *str, char c, char **word_end)
{
	while (*str == c)
		str++;
	*word_end = (char *)ft_strchr(str, c);
	if (!*word_end)
		*word_end = (char *)ft_strchr(str, '\0');
	return ((char *)str);
}

static char	*copy_words(const char *s_words, size_t n)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(s_words);
	if (n < len)
		len = n;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	tmp = ft_memcpy(tmp, s_words, len);
	tmp[len] = '\0';
	return (tmp);
}

static void	free_result_array(char **result, int count)
{
	while (count--)
		free(result[count]);
	free(result);
}

char	**ft_split(char const *str, char c)
{
	size_t	word_count;
	char	**res;
	size_t	n;
	char	*word_start;
	char	*word_end;

	word_count = g_wc(str, c);
	res = malloc(sizeof(char *) * (word_count + 1));
	if (res == NULL)
		return (NULL);
	n = 0;
	while (n < word_count)
	{
		word_start = f_nw(str, c, &word_end);
		res[n] = copy_words(word_start, word_end - word_start);
		if (!res[n])
		{
			free_result_array(res, n);
			return (NULL);
		}
		str = word_end;
		n++;
	}
	res[n] = NULL;
	return (res);
}
