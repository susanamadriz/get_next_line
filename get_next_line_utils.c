//funciones que puedes usar son (ft_strjoin) (ft_substr) (ft_strlen) (ft_strchr) (ft_strdup)
//animo ;) ! i will stay here

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

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