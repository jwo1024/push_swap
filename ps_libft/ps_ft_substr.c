#include	"push_swap.h"

char	*ps_ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ps_ft_strlen(s);
	if (len == 0 || (unsigned int)s_len <= start)
	{
		str = (char *)malloc(sizeof(char));
		if (str)
			*str = '\0';
		return (str);
	}
	if (s_len < len)
		len = s_len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ps_ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
