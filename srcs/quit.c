#include "cube3d.h"

void	quit(int fd)
{
	close(fd);
	ft_putstr_fd("Map invalid", 2);
	exit(0);
}
