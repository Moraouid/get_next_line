/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:20:21 by sel-abbo          #+#    #+#             */
/*   Updated: 2024/12/01 17:42:56 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = (char *)malloc(len_s1 + len_s2 + 1);
	if (!res)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (!c)
		return ((char *)&s[i]);
	return (0);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	len_a;

	i = 0;
	if (!s || start >= (unsigned int)ft_strlen(s))
		return (ft_calloc(1, 1));
	len_a = ft_strlen(s) - start;
	if (len > len_a)
		len = len_a;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	while (s[start] && i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
char	*ft_strdup(const char *src)
{
	char	*str;
	int		s;

	s = ft_strlen(src);
	str = malloc(s + 1);
	if (!src)
		return (0);
	ft_memcpy(str, src, s);
	str[s] = '\0';
	return (str);
}
