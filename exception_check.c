#include "push_swap.h"

void	argc_check(int argc)
{
	if (argc == 1)
		exit(0);
}

static int	is_num(const char *str)
{
	while (*str)
	{
		if (!(('0' <= *str && *str <= '9') || *str == '-'))
			return (0);
		str++;
	}
	return (1);
}

static int	has_duplicates(char const *argv[], int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i + 1;
		while (j < size)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j++]))
				return (1);
	}
	return (0);
}

int	argv_check(char const *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!is_num(argv[i]))
			return (print_error());
		if (ft_atoi(argv[i]) < -2147483648 || ft_atoi(argv[i]) > 2147483647)
			return (print_error());
		i++;
	}
	if (has_duplicates(argv, i))
		return (print_error());
	return (0);
}

void	exception_check1(int argc, char const *argv[])
{
	char	**split;

	argc_check(argc);
	if (split_check(argv + 1))
	{
		split = ft_split(argv[1], ' ');
		exception_check2(split_word_count(split), &split);
		split_free(&split);
	}
	else
		exception_check3(argc, argv);
}
