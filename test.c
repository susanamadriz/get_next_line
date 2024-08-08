/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuan-ma <sjuan-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:02:33 by sjuan-ma          #+#    #+#             */
/*   Updated: 2024/08/08 21:34:12 by sjuan-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *more_info(char *save, int fd)
{
    ssize_t bytes_read = 1;
    char *buf, *aux, *raw = ft_substr(save, 0, ft_strlen(save));

    while (bytes_read != 0 && (!ft_strchr(raw, '\n')))
    {
        if (!(buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1))))
        {
            free(raw);
            return (NULL);
        }
        if ((bytes_read = read(fd, buf, BUFFER_SIZE)) < 0)
        {
            free(buf);
            free(raw);
            return (NULL);
        }
        aux = raw;
        raw = ft_strjoin(aux, buf);
        free(aux);
        free(buf);
    }
    return (raw);
}

char *cut_line(char *raw)
{
	char *result;

	if (raw && ft_strchr(raw, '\n'))
		result = ft_substr(raw, 0, (ft_strlen(raw) - ft_strlen(ft_strchr(raw, '\n') + 1)));
	else
		result = ft_strdup(raw);
	return (result);
}

char *update_save(char *raw)
{
	char *save;
	char *aux;

	aux = ft_strchr(raw, '\n');
	if (aux)
		save = ft_substr(aux, 1, ft_strlen(aux));  // El caso en que teneomos linea nueva.  No estamos al finaal
	else
			// si estamos al final de la fichera
		return (NULL);
	return (save);
}

char *get_next_line(int fd)
{
    char *newstr;
    char *raw;
    static char *save = NULL;

    raw = more_info(save, fd);
    free(save);
    if (!raw)
        return (NULL);
    if (raw[0] == 0)
    {
        free(raw);
        return(NULL);
    }
    newstr = cut_line(raw);
    if (!newstr)
    {
        free(raw);
        return NULL;
    }
    save = update_save(raw);
    free(raw);	
    return (newstr);
}

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*str;
// 	int i = 0;

// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <filename>\n", argv[0]);
// 		return (1);
// 	}
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}

// //	str = get_next_line(fd);
// 	while (i < 1)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		free(str);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
