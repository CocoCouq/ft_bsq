#include "bsq.h"

int	_check_char(char *s, t_info *info)
{
	int		i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] != '\n' && s[i] != info->vide && s[i] != info->ob)
			return (0);
		else if (s[i] == '\n' && s[i + 1] != '\0')
			return (0);
		i++;
	}
	if (i != info->ncol)
		return (0);
	return (1);
}

int	_init_tab(t_info *info, int fd)
{
	int		i;
	int		nb;
	char	*s;

	i = 0;
	nb = info->nline;
	if (!(info->map = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (0);
	s = _get_line(fd);
	info->ncol = _strlen(s);
	info->map[i] = s;
	info->map[info->nline]= 0;
	if (!(_check_char(info->map[i], info)))
	{
		free(info->map[i]);
		info->map[i] = 0;
		write(2, "map error\n", 10);
		return (_free_tab(info));
	}
	return (1);
}

int	_get_map(t_info *info, int fd)
{
	char	buf[1];
	int		i;
	int		r;

	i = 0;
	if (!(_init_tab(info, fd)))
		return (0);
	while (++i < info->nline)
	{
		if (!(info->map[i] = _mallocstr(info->ncol)))
			return (_free_tab(info));
		r = read(fd, info->map[i], info->ncol);
		info->map[i][(r < 0) ? 0 : r] = '\0';
		if (!(_check_char(info->map[i], info)))
		{
			_free_str(&info->map[i]);
			write(2, "map error\n", 10);
			return (_free_tab(info));
		}
	}
	if ((read(fd, buf, 1) != 0) && write(2, "map error\n", 10))
		return (_free_tab(info));
	return (1);
}
