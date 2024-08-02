/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuan-ma <sjuan-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:02:33 by sjuan-ma          #+#    #+#             */
/*   Updated: 2024/08/02 20:44:55 by sjuan-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *more_info(char *save, int fd)
{
	ssize_t bytes_read;
	char *buf;
	char *aux;
	
	bytes_read = 1;
//	if (!save)
//		save = ft_calloc(sizeof(char), (1));
//	if (!save)
//		return (NULL);
	//printf("SAVE1:%s\n", save);
	//printf("EMPIEZA EL WHILE\n");
	while (bytes_read > 0 && (!ft_strchr(save, '\n')))
	{
		buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!buf)
			return NULL;
//		printf("ENTRA AL WHILE \n");
		bytes_read = read(fd, buf, BUFFER_SIZE);
//		printf("%i\n", i);
		if (bytes_read < 0)
		{
			free(buf);
			return NULL;
		}
		buf[bytes_read] = 0;
	//	printf("BUF: %s\n", buf);
//		printf("SAVE2:%s\n", save);	
		if (*buf == '\0')
		{
			printf("HOLA ULTIMA LINEA");
			free(buf);
			return (save);
		}
	//	printf("SAVE: %s y AUX: %s\n", save, aux);
		aux = save;
		save = ft_strjoin(aux, buf);

		free(buf);					//Tienes que liberar el original
	}
	return (save);
}

char *cut_line(char *raw)
{
	char *result;
	
	// printf("AQUI %s\n", raw);
	result = NULL;
	if (raw)
		result = ft_substr(raw, 0, (ft_strlen(raw) - ft_strlen(ft_strchr(raw,  '\n'))));
//	printf("AQUI %s\n", raw);
	return (result);
}

char *update_save(char *raw)
{
	char *save;
//	printf("SAVE: %s\n", save);
	save = ft_strchr(raw, '\n') + 1; 
	if ((unsigned long)save == (unsigned long)1)
		return (NULL);
	return (save);
}

char *get_next_line(int fd)
{
	char *newstr;
	char *raw;
	static char *save;
	
 
	//Paso 1
	
	raw = more_info(save, fd); 			//
  	if (!raw)
		return NULL;
//	printf("------%s\n", raw);
	if (raw[0] == 0)
		return(NULL);
	//Paso 2
	newstr = cut_line(raw);
	if (!newstr)
	{	
		free(raw);
		if (save)
			free (save);
		return NULL;
	}
	
	//Paso 3
	save = update_save(raw);
//	free(raw);
//	printf("NEWSTR: %s\n", newstr);

	return (newstr);
}