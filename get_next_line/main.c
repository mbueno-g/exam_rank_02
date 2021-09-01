#include "get_next_line.h"

int	main()
{
	char *line;
	int fd;

	fd = open("nl", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	/*while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s\n", line);
	}*/
}
