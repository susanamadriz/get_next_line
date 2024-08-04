/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuan-ma <sjuan-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:02:33 by sjuan-ma          #+#    #+#             */
/*   Updated: 2024/08/04 16:59:33 by sjuan-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *more_info(char *save, int fd)
{
	ssize_t bytes_read;
	char *buf;
	char *aux;
	
	bytes_read = 1;
	while (bytes_read > 0 && (!ft_strchr(save, '\n')))
	
				//Tienes que liberar el original
	}
	//printf("Function 1 %s\n", save);
	return (save);
}

char *cut_line(char *raw)
{
	char *result;
	
	// printf("AQUI %s\n", raw);
	
	//printf("Raw PRE  CUT: %s\n", raw);
	result = NULL;
	if (raw)
		result = ft_substr(raw, 0, (ft_strlen(raw) - ft_strlen(ft_strchr(raw,  '\n'))));
	//printf("PRE  CUT: %s\n",result);
	//printf("Raw POST CUT: %s\n", raw);
//	printf("AQUI %s\n", raw);
	return (result);
}

char *update_save(char *raw)
{
	char *save;
														//	printf("SAVE: %s\n", save);
														//printf("Raw %s\n", raw);
	save = ft_strchr(raw, '\n');
														//printf("%p\n", save);
	if (save)
		save = ft_substr(save, 1, ft_strlen(save));
														//printf("Save Post: %s\n", save);
	//printf("POST CUT: %s\n",save);
	free(raw);
	return (save);
}

char *get_next_line(int fd)
{
	char *newstr;
	char *raw;
	static char *save = NULL;
	
 
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