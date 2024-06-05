#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <string.h>

#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif


// utils

char *ft_strchr(const char *s, int c);

// get_next_line

char *prueba(int fd);

#endif