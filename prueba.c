#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = strlen(s1);
	len2 = strlen(s2);
	new = calloc ((len1 + len2 + 1), sizeof(char));
	if (new == NULL)
		return (NULL);
	while (i < (len1 + len2))
	{
		while (i < len1)
			new[i++] = *s1++;
		new[i++] = *s2++;
	}
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	if (!s)
		return (0);
	ptr = (char *)s;
	while (*ptr != '\0')
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if (*ptr == (char)c)
		return (ptr);
	return (0);
}


char *prueba(int fd)
{
	ssize_t bytes_read;
	char *buf;  
	char *newstr;
	static char *save;
	int	i;

	i = 0;
	// int i;
	buf = calloc(sizeof(char), (BUFFER_SIZE + 1));
    if (!buf)
		return NULL;
	newstr = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!newstr)
		return NULL;
	if(!ft_strchr(save, '\n'))
	{
		while (!ft_strchr(newstr, '\n') && bytes_read > 0 && buf[i]);
		{
			i = 0;
			bytes_read = read(fd, buf, BUFFER_SIZE);
			if (bytes_read == -1)
			{
				free(buf);
				return NULL;
			}
			while (i < BUFFER_SIZE)	
			{
				newstr[i] = buf[i];
				i++;
				if (buf[i] == '\n')
				{
					newstr[i] = '\0';
					return (newstr);
				}
			}
		}
	}
	

	return (newstr);	
}


int main()
{
	int fd;
	int i = -1;
	char *line;
	char *line2;
	char *line3;

	fd = open("/home/sjuan-ma/Desktop/get_next_line/she_dont_give_a_fo", O_RDONLY);
	if(fd == -1)
	{
		printf("Error al abrir el archivo");
		return 1;
	}
	//while (1)
	//{
		line = prueba(fd);
		printf("%s\n", line);
		free(line);
		line2 = prueba(fd);
		printf("%s\n", line2);
		line3 = prueba(fd);
		printf("%s", line3);
		/*if (line == NULL)
			break;*/
    	// free(line);
		// line = NULL;
	//}
	free(line3);
	free(line2);
	close(fd);
	return 0;
}