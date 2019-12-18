#include "bsq.h"

char	*_get_line(int fd)
{
	char	buf[2];
	char	*ptr;
	char	*tmp;
	int		r;

	r = 1;
	ptr = 0;
	while (r && (r = read(fd, &buf, 1)) > 0)
	{
		buf[r] = '\0';
		tmp = _strjoin(ptr, buf);
		if (ptr)
			free(ptr);
		ptr = tmp;
		r = (ptr[_strlen(ptr) - 1] != '\n');
	}
	if (r < 0)
	{
		_free_str(&ptr);
		return (0);
	}
	return (ptr);
}

int		_isprintable(char *s)
{
	int		i;

	i = _strlen(s) - 1;
	if (s[i] != '\n')
		return (0);
	while (--i >= 0)
	{
		if (s[i] < 32 || s[i] >= 127)
			return (_free_str(&s));
	}
	return (1);
}

int		_save_info(t_info *info, char *s)
{
	int		i;

	i = _strlen(s) - 1;
	if (!(_isprintable(s)))
		return (0);
	info->plein = s[--i];
	info->ob = s[--i];
	info->vide = s[--i];
	s[i] = '\0';
	while (--i >= 0)
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
	info->nline = _atoi(s);
	info->ncol = 0;
	return (1);
}

int		_get_info(t_info *info, int fd)
{
	char	*s;

	s = 0;
	info->map = 0;
	if (!(s = _get_line(fd)) || _strlen(s) - 1 < 4)
		return (_free_str(&s));
	if (!(_save_info(info, s)))
		return (_free_str(&s));
	_free_str(&s);
	if (info->plein == info->ob || \
	info->plein == info->vide || info->vide == info->ob)
		return (0);
	return (1);
}
