/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:15:26 by rbuitrag          #+#    #+#             */
/*   Updated: 2025/01/25 14:29:57 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strdup(char *src)
{
    char    *dest;
    int        i;

	i = 0;
	if (!src)
		return (NULL);
    while (src[i])
        i++;
    dest = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    while (src[i])
    {
       dest[i] = src[i];
       i++;
    }
    dest[i] = '\0';
    return (dest);
}

char    *get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	char			line[700000];
	static int		buffer_read;
	static int		buffer_pos;
	int				i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break ;
		}
		line[i] = buffer[buffer_pos++];
		if (line[i++] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int	main(void)
{
/*	int	fd;

	fd = open("prueba.txt", O_RDONLY);
	if (fd == -1)
	{
		perror ("open");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
*/	
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("fede", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	while (count < 3)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("[%d]:%s", count, line);
			free(line);
			count++;
		}
	}
	close(fd);
		return (0);
}
