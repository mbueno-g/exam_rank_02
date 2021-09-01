#include "get_next_line.h"


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*x;
	int			i;
	int			a;

	if (!s1 || !s2)
		return (NULL);
	x = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!x)
		return (NULL);
	i = 0;
	a = 0;
	while (s1[i] != '\0')
		x[a++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		x[a++] = s2[i++];
	x[a] = '\0';
	return (x);
}

char	*get_next_line(int fd)
{
	int len;
	int ret;
	char *aux;
	int i;
	char c;
	char	*line;

	ret = 0;
	len = 1;
	line = malloc(len);
	if (!line)
		return (NULL);
	line = NULL;
	while((ret = read(fd, &c, 1) > 0) && c != '\n')
	{
		len++;
		aux = malloc(len);
		if (!aux)
		{
			free(line);
			return (NULL);
		}
		i = -1;
		while(++i < len - 2)
			aux[i] = line[i];
		aux[i] = c;
		aux[i + 1] = '\0';
		free(line);
		line = aux;
	}
	if (ret > 0 && c == '\n')
	{
		/*if (line == NULL)
			line = "";
		return (ft_strjoin(line, "\n"));*/
		len++;
		aux = malloc(len);
		if (!aux)
		{
			free(line);
			return (NULL);
		}
		i = -1;
		while(++i < len - 2)
			aux[i] = line[i];
		aux[i] = c;
		aux[i + 1] = '\0';
		free(line);
		line = aux;
	}
	return (line);
}
