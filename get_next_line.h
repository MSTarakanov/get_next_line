#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 3

int		get_next_line(int fd, char **line);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		read_and_slash(int fd, char *buf);
void	ft_putendl(char const *s);

#endif
