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
			leftover = NULL;
			return (NULL);
		}
		else if (read_elements == 0)
			return (leftover);
		buffer[read_elements] = '\0';
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

char	*divide_line(char **leftover)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	while ((*leftover)[i] != '\0' && (*leftover)[i] != '\n')
		i++;
	temp = *leftover;
	line = ft_substr(temp, 0, i + 1);
	*leftover = ft_substr(temp, i + 1, ft_strlen(*leftover) - 1);
	if (temp)
		free(temp);
	temp = NULL;
	if (!line)
	{
		if (*leftover)
			free(*leftover);
		*leftover = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*buffer;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
	{
		if (leftover)
			free(leftover);
		leftover = NULL;
		return (NULL);
	}
	if (!leftover)
		leftover = ft_strdup("");
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	leftover = read_line(fd, buffer, leftover);
	if (!leftover)
		return (NULL);
	line = divide_line(&leftover);
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (line);
}
