
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
	new[i] = '\0'; 
	return (new);
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
	ssize_t bytes_read;
	char *buf;
	char *aux;
	char *newstr;
	static char *save;
	int i;

	i = 0;
	if (!save)
		save = ft_strdup("");

	buf = calloc(sizeof(char), (BUFFER_SIZE + 1));
    if (!buf)
		return NULL;
	while(!ft_strchr(save, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buf);
			return NULL;
		}
		buf[bytes_read] = '\0';
		aux = save;
		aux = ft_strjoin(aux, buf);
		printf("\nAUX: %s", aux);
		printf("\nSAVE: %s", save);
		save = aux;
		printf("\nSAVE2: %s", save);
	}
	while(save[i] != '\n')
		i++;
	printf("\nI: %i\n", i);
	newstr = ft_substr(save, 0, i);
	printf("\nNEWSTR: %s", newstr);
/* 	if(ft_strchr(save, '\0'))
	{
		return(save);
		save = NULL;
	}
	if(save == NULL)
		return(NULL); */
	return(newstr);

}

/* int main()
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
	while (1)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
		line2 = get_next_line(fd);
		printf("%s\n", line2);
		line3 = get_next_line(fd);
		printf("%s", line3);
	}
	free(line3);
	free(line2);
	close(fd);
	return 0;
} */

int main(void)
{
    int fd;
    unsigned long long i;
    i = 0;
    fd = open("/home/sjuan-ma/Desktop/get_next_line/she_dont_give_a_fo", O_RDONLY);
    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        return 1;
    }
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (line[0] == '\0') {
            // La línea es vacía, imprimir un salto de línea manualmente
            printf("\n");
        } else {
            printf("%s\n", line);
        }
    i++;
        free(line);
    }
    printf("\nTotal lines: %lld\n", i);
    close(fd);
    return 0;
}