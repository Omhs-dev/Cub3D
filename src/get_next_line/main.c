#include <unistd.h>
#include <fcntl.h>
#include "../../include/get_next_line.h"

int main(void)
{
    int fd;
	char *line;
	fd = open("map.cub.cub", O_RDONLY);

	line = get_next_line(fd);
	while(line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}

	return (0);
}


// int main()
// {
// 	mmain();
// 	system("leaks a.out");
// }