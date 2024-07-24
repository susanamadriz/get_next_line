/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuan-ma <sjuan-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:02:33 by sjuan-ma          #+#    #+#             */
/*   Updated: 2024/07/24 18:40:25 by sjuan-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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