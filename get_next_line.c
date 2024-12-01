/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:20:31 by sel-abbo          #+#    #+#             */
/*   Updated: 2024/12/01 22:27:35 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int  fd)
{
	static char	*rem;
	char	*line;
	char	BUFFER;
	size_t	b_read;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	b_read = read(fd, BUFFER, BUFFER_SIZE)
	if (b_read <= 0)
		return (free(BUFFER), NULL);
	BUFFER[b_read] = '\0':
	rem = ft_strjoin(rem, BUFFER)
	if (!rem)
		return (NULL);
	return (line);
}
