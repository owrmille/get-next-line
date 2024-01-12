#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// # include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
char		*set_line(char *line);
char		*fill_line(int fd, char *leftover, char *buffer);
int			ft_strlen(const char	*str);
char		*ft_strchr(const char	*s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(char const *src);
char		*ft_strjoin(char const	*s1, char const	*s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif