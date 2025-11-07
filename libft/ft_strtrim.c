/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:24:33 by dzhukov           #+#    #+#             */
/*   Updated: 2025/10/27 12:14:37 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	last_id;
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	i = 0;
	while (i < len && ft_isset(s1[len - 1 - i], set))
		i++;
	last_id = len - i;
	i = 0;
	while (i < last_id && ft_isset(s1[i], set))
		i++;
	ptr = (char *)ft_calloc(last_id - i + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	j = 0;
	while (i < last_id)
		ptr[j++] = s1[i++];
	ptr[j] = '\0';
	return (ptr);
}
