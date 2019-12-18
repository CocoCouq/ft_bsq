#include "bsq.h"

void	_print_map(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
	{
		write(1, info->map[i], info->ncol);
		i++;
	}
	_free_tab(info);
}

void	_draw_bsq(t_info *info)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	if (info->sq_size > -1 && info->map)
	{
		while (i < info->sq_size)
		{
			j = 0;
			x = info->x;
			while (j < info->sq_size)
			{
				info->map[info->y][x] = info->plein;
				j++;
				x++;
			}
			info->y++;
			i++;
		}
	}
}

void	_diagonal(t_info *info, int i, int j)
{
	int	k;
	int	size;
	int	save[2];

	size = 0;
	save[0] = i;
	save[1] = j;
	while (info->map[i] && info->map[i][j] == info->vide)
	{
		k = i;
		while (k >= save[0])
			if (info->map[k--][j] == info->ob)
				return ;
		k = j;
		while (k >= save[1])
			if (info->map[i][k--] == info->ob)
				return ;
		if ((++size) > info->sq_size)
		{
			info->sq_size = size;
			info->x = save[1];
			info->y = save[0];
		}
		(++i && ++j);
	}
}


void	_solver(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	info->y = -1;
	info->x = -1;
	info->sq_size = -1;
	while (info->map[++i])
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == info->vide)
				_diagonal(info, i, j);
		}
	}
	_draw_bsq(info);
	_print_map(info);
}
