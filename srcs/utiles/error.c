#include "../../includes/cub3d.h"

void	print_err_exit(int errno)
{
	printf("Error :");
	if (errno == NOFILE)
		printf("The file name or data is incorrect.\n");
	else if (errno == NOWALL)
		printf("This map is not surrounded by walls.\n");
	else if (errno == WRONGDATA)
		printf("This data is incorrect.\n");
	exit(errno);
}
