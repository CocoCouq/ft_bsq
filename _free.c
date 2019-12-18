#include "bsq.h"

int	_free_tab(t_info *info)
{
	int	i;

	i = 0;
	while (info->map && info->map[i])
	{
		free(info->map[i]);
		info->map[i] = 0;
		i++;
	}
	if (info->map)
	{
		free(info->map);
		info->map = 0;
	}
	return (0);
}

int	_free_str(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = 0;
	}
	return (0);
}
