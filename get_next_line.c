/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:20:31 by sel-abbo          #+#    #+#             */
/*   Updated: 2024/12/01 23:29:01 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_join(fd, rem)
{
	char	BUFFER;
	size_t	b_read;

	b_read = read(fd, BUFFER, BUFFER_SIZE)
		if (b_read < 0)
			return (NULL);
		if (b_read = 0)
			break;
		BUFFER[b_read] = '\0':
		rem = ft_strjoin(rem, BUFFER);
	return (rem);
}

static char	*line_extra(char	**rem)
{
	char	*line;
	char	*new_line;

	new_line = ft_strchr(*rem, '\n');
	if (!new_line)
		return (NULL);
	line = ft_substr(*rem, 0, new_line - *rem + 1);
	*rem = ft_strdup(new_line + 1);
	return(line);	
}

char	*get_next_line(int  fd)
{
	static char	*rem;
	char	*line;
	size_t	b_read;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(rem, '\n'))
	{
		rem = read_join(fd, rem);
		if (!rem)
			return (NULL);	
	}
	line = line_extra(&rem);
	if(!line && rem)
	{
		line = ft_strdup(rem);
		free(rem);
		rem = NULLL;
	}
	return (line);
}
