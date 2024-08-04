//funciones que puedes usar son (ft_strjoin) (ft_substr) (ft_strlen) (ft_strchr) (ft_strdup)
//animo ;) ! i will stay here
#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	char	*pointer;

	total_size = count * size;
	if (size != 0 && total_size >= SIZE_MAX)
		return (NULL);
	if (total_size > 0)
		pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	while (total_size > 0)
	{
		pointer[total_size - 1] = 0;
		total_size--;
	}
	return (pointer);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if(s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1,1));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new = ft_calloc(sizeof(char), (len + 1));
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
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = ft_calloc ((len1 + len2 + 1), sizeof(char));
	if (new == NULL)
		return (NULL);
	if (!s1)
		return(ft_strdup(s2));
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
	return (NULL);
}
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*new;
	i = 0;
	if (!s1)
		return (NULL);
	new = ft_calloc(ft_strlen(s1), sizeof(char) + 1);
	if (new == NULL)
		return (NULL);
	else { printf("\n\n\n |StrDup: %p|\n\n\n", new); }
	while (*s1)
		new[i++] = *s1++;
	new[i] = '\0';
	return (new);
}