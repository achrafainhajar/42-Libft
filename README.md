
#include "get_next_line.h"
#include <string.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	loopread(char **ptr, char *buff, char	**str, int *l)
{
	int		i;
	char	dest[12000];
	char	*s;

	s = NULL;
	buff[*l] = 0;
	i = -1;
	*str = ft_strjoin(*str, buff);
	if (ft_strchr(*str, '\n') != 0)
	{
		s = ft_strdup(*str);
		*ptr = ft_strchr(strcpy(dest, *str), '\n');
		while (s[++i])
		{
			if (s[i] == '\n')
			{
				free(*str);
				*str = ft_substr(s, 0, i + 1);
				free(s);
				return (1);
			}
		}
		free(s);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	int			i;
	char		*buff;
	char		*str;
	int			l;

	l = 1;
	buff = NULL;
	str = ft_strdup("");
	i = 0;
	if (!ptr)
		ptr = "";
	if (ft_strchr(ptr, '\n'))
	{
		while (ptr[i])
		{
			if (ptr[i] == '\n')
			{
				free(buff);
				free(str);
				str = ft_substr(ptr, 0, i + 1);
				ptr = ft_strchr(ptr, '\n');
				return (str);
			}
			i++;
		}
	}
	else
	{
		free(str);
		str = ft_strdup(ptr);
	}
	while (l != 0)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE);
		l = read(fd, buff, BUFFER_SIZE);
		if (l > 0 && loopread(&ptr, buff, &str, &l) == 1)
			return (str);
		else if ((l == 0 && (strcmp(ptr, "") == 0
					&& strcmp(str, "") == 0)) || l == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		else if (l == 0)
			ptr = NULL;
	}
	free(buff);
	return (str);
}
