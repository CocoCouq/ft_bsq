#include "bsq.h"

int		_operation(t_info *info, int fd)
{
	if (_get_info(info, fd))
	{
		if (_get_map(info, fd))
			_solver(info);
	}
	else
		write(2, "map error\n", 10);
	return (1);
}

int		_multiple_file(char **av, int ac, t_info *info)
{
	int		i;
	int		fd;

	i = 0;
	fd = 0;
	while (++i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) < 0)
			write(2, "map error\n", 10);
		else
		{
			_operation(info, fd);
			if (close(fd) < 0)
				write(2, "map error\n", 10);
		}
		if ((ac - 1 - i))
			write(1, "\n", 1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	t_info	info;

	i = 0;
	fd = 0;
	info.map = 0;
	if (ac - 1 == 0)
		_operation(&info, fd);
	else
		_multiple_file(av, ac, &info);
	return (0);
}
