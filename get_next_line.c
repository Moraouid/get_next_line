/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:20:31 by sel-abbo          #+#    #+#             */
/*   Updated: 2024/12/03 18:16:51 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_join(int fd, char *rem)
{
	char	BUFFER[BUFFER_SIZE + 1];
	int	b_read;

	b_read = read(fd, BUFFER, BUFFER_SIZE);
	if (b_read < 0)
	{
		free(rem);
		return (NULL);
	}
	if (b_read == 0)
		return(rem);
	BUFFER[b_read] = '\0';
	rem = ft_strjoin(rem, BUFFER);
	if (!rem)
		return (NULL);
	return (rem);
}

static char	*line_extra(char	**rem)
{
	char	*line;
	char	*new_line;
	char	*tmp;

	new_line = ft_strchr(*rem, '\n');
	if (!new_line)
		return (NULL);
	line = ft_substr(*rem, 0, new_line - *rem + 1);
	if (!line)
		return (NULL);
	tmp = ft_strdup(new_line + 1);
	if (!tmp)
	{
		free(line);
		return (NULL);
	}
	free(*rem);
	*rem = tmp;
	return (line);	
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char	*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(rem);
		rem = NULL;
		return (NULL);
	}
	if (!rem)
		rem = ft_strdup("");
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
		rem = NULL;
	}
	return (line);
}
