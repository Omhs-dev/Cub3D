#include "../../includes/structs.h"

int error(int errnum)
{
    if (errnum == WRONG_ARGS_NUM)
	{
		printf("Error\n Wrong number of arguments\n");
        exit(EXIT_FAILURE);
    }
    else if (errnum == NAME_LENGTH)
    {
        printf("Error\n filename too long or too short\n");
        exit(EXIT_FAILURE);
    }
    else if (errnum == WRONG_EXTENSION)
    {
        printf("Error\n Wrong extension (file must have .cub extension)\n");
        exit (EXIT_FAILURE);
    }
    else if (errnum == FILE_OPEN)
    {
        printf("Error\n %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else if (errnum == MAP_DESCRIPTION)
    {
        printf("Error\n Invalid map description\n");
        exit(EXIT_FAILURE);
    }
    else if (errnum == INVALID_MAP)
    {
        printf("Error\n Invalid map\n");
        exit(EXIT_FAILURE);
    }
    return (0);
}
