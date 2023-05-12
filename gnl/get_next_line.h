
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_info {
	char	*buf;
	char	*save;
	char	*line;
	char	*ret;
	int		fd;
	int		idx;
}				t_info;

char	*get_next_line(int fd);

#endif
