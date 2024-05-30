#include "../../includes/structs.h"

int is_rgb_value(char *str)
{
    int i;

    i = 0;
    while (*str)
    {
        i++;
        if (!ft_isdigit(*str))
            return (0);
        str++;
    }
    if (i == 0 || i > 3)
        return (0);
    i = ft_atoi(str - i);
    if(i < 0 || i > 255)
        return (0);
    return (1);
}
