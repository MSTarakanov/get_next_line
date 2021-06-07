#include "get_next_line.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *ptrdst;
	char *ptrsrc;

	if (!dst && !src)
		return (NULL);
	ptrdst = (char*)dst;
	ptrsrc = (char*)src;
	while (n > 0)
	{
		*ptrdst = *ptrsrc;
		ptrdst++;
		ptrsrc++;
		n--;
	}
	return (dst);
}

size_t		ft_strlcpy(char *destination, const char *source, size_t n)
{
	size_t len;

	if (!source && !destination)
		return (0);
	len = ft_strlen(source);
	if (len + 1 < n)
	{
		ft_memcpy(destination, source, len + 1);
	}
	else if (n != 0)
	{
		ft_memcpy(destination, source, n - 1);
		destination[n - 1] = '\0';
	}
	return (len);
}

char		*save_has_n(char *save, char **line)
{
	char *n;

	n = NULL;
	*line = NULL;
	if ((n = ft_strchr(save, '\n')))
	{
		*n = '\0';
		*line = ft_strdup(save);
		ft_strlcpy(save, n + 1, BUFFER_SIZE);
	}
	else if (save)
		*line = ft_strdup(save);
	else
	{
		if (!(*line = (char*)malloc(1)))
			return (NULL);
		*line[0] = '\0';
	}
	return (n);
}

void		free_save(char **save)
{
	if (*save)
		free(*save);
	*save = NULL;
}

int			get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	static char		*save = NULL;

	if (!line || BUFFER_SIZE <= 0)
		return (-1);
	if ((save_has_n(save, line)) && save)
		return (1);
	while ((ret = read_and_slash(fd, buf)) > 0)
	{
		if ((ft_strchr(buf, '\n')))
		{
			free_save(&save);
			save = ft_strchr(buf, '\n');
			*save = '\0';
			save = ft_strdup(save + 1);
			*line = ft_strjoin(*line, buf);
			break ;
		}
		*line = ft_strjoin(*line, buf);
	}
	if (ret > 0 && save && *line)
		return (1);
	free_save(&save);
	return (ret < 0 ? -1 : 0);
}
