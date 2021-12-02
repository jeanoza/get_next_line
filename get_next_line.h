#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strndup(const char *src, size_t len);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *b, int c, unsigned int len);

#endif