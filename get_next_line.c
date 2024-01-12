#include "get_next_line.h"

char	*read_line(int fd, char *buffer, char *leftover)
{
	int		read_elements;
	char	*temp;

	read_elements = 1;
	while (read_elements > 0)
	{
		read_elements = read(fd, buffer, BUFFER_SIZE);
		if (read_elements == -1)
		{
			if (leftover)
				free(leftover);
			if (buffer)
				free(buffer);
			return (NULL);
		}
		else if (read_elements == 0)
			return (leftover);
		temp = leftover;
		leftover = ft_strjoin(temp, buffer);
		if (temp)
			free (temp);
		temp = NULL;
		if (ft_strchr(leftover, '\n'))
			break ;
	}
	return (leftover);
}

char	*divide_line(char *line)
{
	return ();
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*buffer;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
	{
		if (buffer)
			free(buffer);
		if (leftover)
			free(leftover);
		return (NULL);
	}
	if (!leftover)
		leftover = ft_strdup("");
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, leftover);
	if (!line)
		return (NULL);
	leftover = divide_line(line);
	return (line);
}

