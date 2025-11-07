/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:52:48 by dzhukov           #+#    #+#             */
/*   Updated: 2025/10/27 12:14:30 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *str, char del)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != del && (i == 0 || str[i - 1] == del))
			count++;
		i++;
	}
	return (count);
}

void	*ft_free(char **arr, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	words;
	char	**arr;

	words = ft_count_words(s, c);
	arr = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < words)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		while (s[j] && (s[j] != c))
			j++;
		arr[i] = ft_substr(s, 0, j);
		if (!arr[i])
			return (ft_free(arr, i));
		i++;
		s += j;
	}
	return (arr);
}
