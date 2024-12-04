#include "get_next_line_bonus.h"

static char	*ft_free_bonus(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin_bonus(buffer, buf);
	free(buffer);
	return (temp);
}

static char	*ft_next_bonus(char *buffer)
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
	line = ft_calloc_bonus((ft_strlen_bonus(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

static char	*ft_line_bonus(char *buffer)
{
	int		i;
	int		j;
	char	*mem;

	i = 0;
	if (!buffer[i])
	{
		// free(buffer);
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	mem = ft_calloc_bonus(i + 2, sizeof(char));
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

static char	*ft_read_bonus(int fd, char *resultat)
{
	char	*buffer;
	int		number_read;

	if (!resultat)
		resultat = ft_calloc_bonus(1, 1);
	buffer = ft_calloc_bonus((size_t)BUFFER_SIZE + 1, sizeof(char));
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
		resultat = ft_free_bonus(resultat, buffer);
		if (ft_strchr_bonus(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (resultat);
}

char	*get_next_line_bonus(int fd)
{
	static char	*buffer[10248];
	char		*line;

	if (fd < 0 || fd >= 10248 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_bonus(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line_bonus(buffer[fd]);
	buffer[fd] = ft_next_bonus(buffer[fd]);
	return (line);
}
// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;

// 	fd1 = open("fd1.txt", O_RDONLY);
// 	fd2 = open("fd2.txt", O_RDONLY);
// 	fd3 = open("fd3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 	line = get_next_line_bonus(fd1);
// 	if (line) 
// 	{
//    		printf("%s", line);
//     	free(line);
// 	}
// 	line = get_next_line_bonus(fd2);
// 	if (line) 
// 	{
//     	printf("%s", line);
//     	free(line);
// 	}
// 	line = get_next_line_bonus(fd3);
// 	if (line) 
// 	{
//     	printf("%s", line);
//     	free(line);
// 	}
// 	i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }