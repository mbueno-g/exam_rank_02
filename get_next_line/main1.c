#include "get_next_line1.h"

int	main(void)
{
	int x;
	int y;
	char *line;

	fd = open("text.txt", O_RDONLY);
	x = get_next_line(&line);
	y = 1;
	while (x >= 0)
	{
		printf("line %d read ---> %s\n", y, line);
		free(line);
		line = NULL;
		if (x == 0)
			break ;
		x = get_next_line(&line);
		y++;
	}
	return (0);
}
