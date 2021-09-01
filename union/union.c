int	main(int argc, char **argv)
{

	int used[255];
	int i;
	int j;
	unsigned char c;

	i = 0;
	if (argc == 3)
	{
		while (i < 255)
			used[++i] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				c = argv[i][j];
				if (!used[c])
				{
					used[c] = 1;
					write(1, &c, 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, '\n', 1);
	return (0);
}
