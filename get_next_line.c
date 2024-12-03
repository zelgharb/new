#include "get_next_line.h"

static char	*ft_free(char *buffer, char *s2)
{
	char	*tmp;

	tmp = NULL;
	if (buffer && s2)
		tmp = ft_strjoin(buffer, s2);
	else if (buffer)
		tmp = buffer;
	if (buffer && !tmp)
		free(buffer);
	return (tmp);
}

static char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

static char	*ft_line(char *buffer)
{
	int		i;
	int		j;
	char	*mem;

	i = 0;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	mem = ft_calloc(i + 2, sizeof(char));
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		mem[j] = buffer[j];
		j++;
	}
	if (buffer[j] && buffer[j] == '\n')
		mem[j++] = '\n';
	return (mem);
}

static char	*ft_read(int fd, char *resultat)
{
	char	*buffer;
	int		number_read;

	if (!resultat)
		resultat = ft_calloc(1, 1);
	buffer = ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	number_read = 1;
	while (number_read > 0)
	{
		number_read = read(fd, buffer, BUFFER_SIZE);
		if (number_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[number_read] = '\0';
		resultat = ft_free(resultat, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (resultat);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}