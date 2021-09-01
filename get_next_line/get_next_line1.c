#include "get_next_line1.h"

int	get_next_line(char **line)
{
	int 	i;
	int 	len;
	int 	ret;
	char 	*aux;
	char	c;

	len = 1;
	ret = 0;
	*line = malloc(len);
	if (!line)
		return (-1);
	(*line)[0] = '\0';
	while ((ret = read(0, &c, 1) > 0) && c != '\n')
	{
		len++;
		aux = malloc(len);
		if (!aux)
		{
			free(*line);
			return (-1);
		}
		i = -1;
		while (++i < len - 2)
			aux[i] = (*line)[i];
		aux[i] = c;
		aux[i + 1] = '\0';
		free(*line);
		*line = aux;
	}
	return (ret);
}
