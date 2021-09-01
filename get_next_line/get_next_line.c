#include "get_next_line.h"

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
	ret = read(fd, &c, 1);
	while(ret > 0)
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
		if (c == '\n')
			return (line);
		else
			ret = read(fd, &c, 1);
	}
	return (line);
}
