#include "../../includes/structs.h"

static int	count_lines(int fd)
{
	int		i = 0;
	char	*temp;

	temp = get_next_line(fd);
	while (temp && i++ < INT16_MAX)
	{
		free(temp);
		temp = get_next_line(fd);
	}
	return (close(fd), i);
}

static char **read_file(char *file)
{
	char	**input;
	char	*temp;
	int		fd;
	int		count;

    fd = open(file, O_RDONLY);
	if (fd < 0)
		error(FILE_OPEN);
	count = count_lines(fd);
	fd = open(file, O_RDONLY);
	input = malloc(sizeof(char *) * (count + 1));
	count = 0;
	temp = get_next_line(fd);
    printf("draw wall\n");
	while(temp)
	{
		input[count++] = temp;
		temp = get_next_line(fd);
	}
    printf("line readfile: %s\n", input[1]);
	return (input[count] = NULL, close(fd), input);
}

static void check_extension(char *filename)
{
	int len;
	char *extension;

	len = ft_strlen(filename);
	if (len < 5 || len > 255)
		error(NAME_LENGTH);
	extension = ft_substr(filename, len - 4, 4);
	if (ft_strncmp(".cub", extension, 4) != 0)
	{
		free(extension);
		error(WRONG_EXTENSION);
	}
	free(extension);
}
t_map *parse(int argc, char **argv)
{
	t_map	*map;
	char	**input;

	if (argc != 2)
		error(WRONG_ARGS_NUM);
    printf("parse here\n");
	check_extension(argv[1]);
	input = read_file(argv[1]);
	map = malloc(sizeof(t_map));
	parse_description(map, input);
    parse_map(map, input);
	return (map);
}
