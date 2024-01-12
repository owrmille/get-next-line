#include "get_next_line.h"

int	ft_strlen(const char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char	*s, int c)
{
	char	*res;
	char	symbol;

	symbol = c;
	res = (char *)s;
	while (*res != symbol)
	{
		if (*res == '\0')
			return (NULL);
		res++;
	}
	return (res);
}

char	*ft_strdup(char const *src)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
	{
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*draft_res;
	char	*res;
	int		total_len;

	if (!s1 && !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	draft_res = (char *)malloc((total_len + 1) * sizeof(char));
	if (!draft_res)
		return (NULL);
	res = draft_res;
	while (*s1)
	{
		*draft_res++ = *s1++;
	}
	while (*s2)
	{
		*draft_res++ = *s2++;
	}
	*draft_res = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	subs_len;

	if (s == NULL)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	subs_len = ft_strlen(s) - start;
	if (len > subs_len)
		len = subs_len;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
