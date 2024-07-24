#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int 	line;
	line = 1;
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);

	printf("%s", str);
	free (str);
	// while (line)
	// {
	// 	printf("%s\n", str);
	// 	free(str);
	// 	str = get_next_line(fd);
	// 	if (!str)
	// 		break;
	// }
	// system("leaks -q a.out");
	// close(fd);
	return (0);
}