int	main(int argc, char **argv)
{
	char used[255];
	int i;
	int j;
	unsigned char c;

	i = 0;
	if (argc == 3)
	{
		while (i < 255)
			used[++i] = 0;
		i = 2;
		while(i < 0)
		{
			j = 0;
			while(argv[i][j])
			{
				c = argv[i][j];
				if (i == 2 && !used[c])
					used[c] = 1;
				if (i == 1 && used[c] == 1)
				{
					used[c] = 2;
					write(1, &c, 1);
				}
				j++;
			}
			i--;
		}
	}
	write(1, '\n',1);
	return (0);
}
