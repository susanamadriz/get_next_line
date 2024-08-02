#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
//	int 	line;
	//int		i = 0;
//	line = 1;
	fd = open(argv[1], O_RDONLY);
	printf("%i\n", argc);

	str = get_next_line(fd);
	while (str)
//	while (i < 16)
	{
		printf("%s\n", str);
		free(str);

		str = get_next_line(fd);
	}
//	while (str)
//	while (i < 16)
//	printf("GNL 2: %s\n", str);
//	free(str);
	
	//	i++;
	// system("leaks -q a.out");
	close(fd);
	return (0);
}