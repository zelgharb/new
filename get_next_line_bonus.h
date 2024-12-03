#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 555
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line_bonus(int fd);
char	*ft_strjoin_bonus(char const *s1, char const *s2);
size_t	ft_strlen_bonus(const char *s);
char	*ft_strchr_bonus(const char *s, int c);
void	*ft_calloc_bonus(size_t nmemb, size_t size);
void	ft_bzero_bonus(void *s, size_t n);

#endif