/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:36:55 by sel-abbo          #+#    #+#             */
/*   Updated: 2024/12/12 19:07:24 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_join(int fd, char *rem)
{
	char	*BUFFER;
	ssize_t	b_read;
	
	b_read = 1;
	if(BUFFER_SIZE < 0)
		return (NULL);
	while (b_read > 0 && !ft_strchr(rem, '\n'))
	{
		BUFFER = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!BUFFER)
			return (free(rem), NULL);
		b_read = read(fd, BUFFER, BUFFER_SIZE);
		if (b_read < 0)
			return (free(rem), free(BUFFER),  NULL);
	
		if (b_read == 0)
			return (free(BUFFER), rem);
		BUFFER[b_read] = '\0';
		rem = ft_strjoin(rem, BUFFER);
		free(BUFFER);
	}
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
	static char	*rem[1024];
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rem[fd])
		 rem[fd] = ft_strdup("");
	rem[fd] = read_join(fd, rem[fd]);
	if (!rem[fd])
		return (NULL);
	line = line_extra(&rem[fd]);
	if (line)
		return (line);
	if (ft_strlen(rem[fd]) > 0)
	{
		line = ft_strdup(rem[fd]);
		free(rem[fd]);
		rem[fd] = NULL;
		return (line);
	}
	return (free(rem[fd]), rem[fd] = NULL, NULL);
}
// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
//     int fd1 = open("test.txt", O_RDONLY); 
//     int fd2 = open("test2.txt", O_RDONLY); 
//     //  if (fd < 0)
//     //  {
//     //      printf("Error: Could not open file.\n");
//     //      return (1);
//     //  }

//     char *line;
// 	line = get_next_line(fd1);
// 	printf("%s", line);
// 	line = get_next_line(fd2);
// 	printf("%s", line);
// 	line = get_next_line(fd1);
// 	printf("%s", line);
// 	line = get_next_line(fd2);
// 	printf("%s", line);
// 	line = get_next_line(fd1);
// 	printf("%s", line);
//     // while ((line = get_next_line(fd)) != NULL)
//     // {
//     //     printf("%s", line);
//     //     free(line);
// 	// 	//line = NULL;
//     // }

//     close(fd1);
//     close(fd2);
//     return (0);
// }
