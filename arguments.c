#include "get_next_line.h"

char *prueba(int fd);

/* int main(int argc, char **argv)
{
	int fd;
	char *line;

	// fd = open("she_dont_give_a_fo", O_RDONLY);
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("Error al abrir el archivo");
		return 1;
	}
	line = prueba(fd);
	printf("1RA LINEA%s\n", line);
	free(line);
	close(fd);
	return 0;
} */

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int 	line;
	line = 1;
	fd = open(argv[1], O_RDONLY);
	str = prueba(fd);
	while (line)
	{
		printf("%s\n", str);
		free(str);
		str = prueba(fd);
		if (!str)
			break;
	}
	system("leaks -q a.out");
	close(fd);
	return (0);
}