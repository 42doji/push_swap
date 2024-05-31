#include "push_swap.h"

int	sorted_check(int argc, char const *argv[])
{
	int	i;

	if (argc == 1)
		return (1);
	if (argc == 2 && ft_atoi(argv[0]) > ft_atoi(argv[1]))
	{
		print_sa();
		return (1);
	}
	i = -1;
	while (++i < argc - 1)
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (0);
	return (1);
}
