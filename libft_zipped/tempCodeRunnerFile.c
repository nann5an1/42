e_t ft_strlen(const char *s)
{
	size_t	i = 0;
	char *str = (char *)s;
	while (str[i] != '\0')
		i++;
	return (i);
}