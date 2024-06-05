#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (new == NULL)
		return (NULL);
	while (*s1)
		new[i++] = *s1++;
	new[i] = '\0';
	return (new);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

char *get_next_line(int fd)
{
	static char *position; // puedes hacer un static char *store -> guardará todas las lineas
	int i;
	int nl;
	char *newstr;
	int fd;
	char buf;
	char *line = malloc(BUFFER_SIZE);


		read(fd, buf, BUFFER_SIZE);
	while (position[i] != '\n' && i > BUFFER_SIZE)
		nl = 0;
		while(position[i] != '\n')
			nl++;
		read(fd, line, nl); //piensa en lo de caracter por caracter
		if(BUFFER_SIZE > nl)
		ft_substr(position, i, (BUFFER_SIZE - i));
		return(newstr);
		i =+ nl;
}

int main(void)
{
		fd = open("/home/sjuan-ma/Desktop/get_next_line/she_dont_give_a_fo", O_RDONLY);
	if(fd == -1)
	{
		printf("Error al abrir el archivo");
	}
	return 0;
}