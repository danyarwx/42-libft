/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:35:45 by dzhukov           #+#    #+#             */
/*   Updated: 2025/10/27 12:14:43 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_count_len(long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * (-1);
		count = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			count;
	char		*str;
	long long	nn;

	nn = n;
	count = ft_count_len(nn);
	str = (char *)ft_calloc(count + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (nn < 0)
	{
		nn = nn * (-1);
		str[0] = '-';
	}
	while (nn > 0)
	{
		str[--count] = (nn % 10) + '0';
		nn = nn / 10;
	}
	return (str);
}
