/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:41:27 by moaljazz          #+#    #+#             */
/*   Updated: 2024/10/27 23:41:29 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	size_t	j;

	i = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	dest = (char *)malloc(s1len + s2len + 1);
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = c;
	while (*s)
	{
		if (*s == ch)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == ch)
	{
		return ((char *)s);
	}
	return (NULL);
}

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	char		*dest_str2;
	const char	*src_str2;

	if (n == 0)
		return (dest_str);
	if (dest_str == 0 && src_str == 0)
		return (NULL);
	dest_str2 = (char *)dest_str;
	src_str2 = (char *)src_str;
	while (n > 0)
	{
		dest_str2[n - 1] = src_str2[n - 1];
		n--;
	}
	return (dest_str2);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*result;

	len = ft_strlen(s) + 1;
	result = (char *)malloc(len);
	if (!result)
	{
		return (NULL);
	}
	ft_memcpy(result, s, len);
	return (result);
}

char	*ft_strndup(const char *s, size_t n)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = malloc(n + 1);
	if (res == NULL)
		return (NULL);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
