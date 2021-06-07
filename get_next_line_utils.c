#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		c;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	newstr = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstr == NULL)
		return (NULL);
	c = 0;
	while (s1[c] != '\0')
	{
		newstr[c] = s1[c];
		c++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		newstr[c] = s2[i];
		i++;
		c++;
	}
	newstr[c] = '\0';
	free(s1);
	return (newstr);
}

char		*ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return (s + i);
	return (NULL);
}

char		*ft_strdup(char *s1)
{
	char	*dup;
	int		size;

	size = 0;
	while (s1[size] != '\0')
		size++;
	dup = (char*)malloc(size + 1);
	if (dup == NULL)
		return (NULL);
	dup[size] = '\0';
	while (size > 0)
	{
		size--;
		dup[size] = s1[size];
	}
	return (dup);
}

int			read_and_slash(int fd, char *buf)
{
	int ret;

	if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
		return (ret);
	buf[ret] = '\0';
	return (ret);
}

void	ft_putendl(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
