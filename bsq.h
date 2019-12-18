#ifndef BSQ_H
# define BSQ_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_info
{
	char			**map;
	int				nline;
	int				ncol;
	char			vide;
	char			ob;
	char			plein;
  	int				x;
	int				y;
	int				sq_size;
}					t_info;

int					_atoi(char *str);
char				*_strjoin(char *s1, char *s2);
int					_strlen(char *str);
int					_get_map(t_info *info, int fd);
int					_get_info(t_info *info, int fd);
char				*_get_line(int fd);
int					_free_tab(t_info *info);
void				_solver(t_info *info);
void				_draw_bsq(t_info *info);
void				_print_map(t_info *info);
int					_free_str(char **str);
char				*_mallocstr(int len);

#endif
