#include <stdlib.h>

char	*_mallocstr(int len)
{
	int		i;
	char	*tmp;

	tmp = 0;
	i = 0;
	tmp = malloc(sizeof(char) * (len + 1));
	if (tmp == 0)
		return (0);
	while (i <= len)
		tmp[i++] = 0;
	return (tmp);
}
