#include "bsq.h"

char	*_strjoin(char *s1, char *s2)
{
	char	*tmp;
	int		i;
	int		len;

	len = 0;
	if (!s1 && !s2)
		return (0);
	else if (!s1)
		len = _strlen(s2);
	else if (!s2)
		len = _strlen(s1);
	else
		len = _strlen(s1) + _strlen(s2);
	if (!(tmp = _mallocstr(len)))
		return (0);
	i = 0;
	while (s1 && *s1)
		*(tmp + (i++)) = *(s1++);
	while (s2 && *s2)
		*(tmp + (i++)) = *(s2++);
	return (tmp);
}
