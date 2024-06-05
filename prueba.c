#include "get_next_line.h"

char *prueba(int fd)
{
	ssize_t bytes_read;
	static char *buf;  
	char *newstr ;
	int	i;

	i = 0;
	// int i;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	newstr = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
	{
		return NULL;
	}
	//while (buf)
	//{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return NULL;
		}
		newstr = buf;
		newstr[BUFFER_SIZE] = '\0';
		//printf("%s", buf);
		/*newstr[i] = buf[i];
		if (newstr[i] == '\n')
		{
		 	newstr[i] = '\0';
			return (newstr);
		i++;
		}*/
	//}
	//free(buf);
	return (newstr);
}


int main()
{
	int fd;
	int i = -1;
	char *line;

	fd = open("/home/sjuan-ma/Desktop/get_next_line/she_dont_give_a_fo", O_RDONLY);
	if(fd == -1)
	{
		printf("Error al abrir el archivo");
		return 1;
	}
	//while (1)
	//{
		line = prueba(fd);
		printf("%s", line);
		free(line);
		line = prueba(fd);
		printf("%s", line);
		/*if (line == NULL)
			break;*/
    	// free(line);
		// line = NULL;
	//}
	free(line);
	close(fd);
	return 0;
}