/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuan-ma <sjuan-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:02:33 by sjuan-ma          #+#    #+#             */
/*   Updated: 2024/07/24 18:22:31 by sjuan-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if(s == NULL)
		return (0);
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
	new = calloc(ft_strlen(s1), sizeof(char) + 1);
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
	new = calloc(sizeof(char), (len + 1));
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
	new = calloc ((len1 + len2 + 1), sizeof(char));
	if (new == NULL)
		return (NULL);
	while (i < (len1 + len2))
	{
		while (i < len1)
			new[i++] = *s1++;
		new[i++] = *s2++;
	}
	//new[i] = '\0'; 
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
char *more_info(char *save, int fd)
{
	ssize_t bytes_read;
	char *buf;
	char *aux = NULL;
	char *aux2;
	
	bytes_read = 1;
	buf = calloc(sizeof(char), (BUFFER_SIZE + 1));
    if (!buf)
		return NULL;
	while (/* !aux ||  */(!ft_strchr(buf, '\n') && bytes_read > 0))
		{
			bytes_read = read(fd, buf, BUFFER_SIZE);
			// printf("BR:%li\n", bytes_read);
			if (bytes_read <= 0)
			{
				free(buf);
				return NULL;
			}
			buf[bytes_read] = '\0';
			aux2 = aux;
			aux = ft_strjoin(aux, buf);
			free(aux2);
		}
	return (aux);
}

char *prueba(int fd)
{
	char *newstr;
	char *raw;
	static char *save;
	char * a ;
	
	if(!ft_strchr(save, '\n'))
		raw = more_info(save, fd);
	newstr = ft_substr(raw, 0, (ft_strlen(raw) - (ft_strlen(save) + 2)));
	// printf("!%li!\n", ft_strlen(save));
	if(save)
		newstr = ft_strjoin(save, newstr);
	save = ft_strchr(raw, '\n') + 1;
	// printf()
	
	return (newstr);
}